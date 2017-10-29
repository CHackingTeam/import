#include "libMS.h"
static int byte_cnt=0;
void rio_readinitb(rio_t* rp,int fd)
{

  rp->rio_fd=fd;
  rp->rio_cnt=0;
  rp->rio_bufptr=rp->rio_buf;
}
static ssize_t rio_read(rio_t *rp,char* usrbuf,size_t n)
{
  int cnt;
  while(rp->rio_cnt<=0)
  {
    rp->rio_cnt=read(rp->rio_fd,rp->rio_buf,sizeof(rp->rio_buf));
    if(rp->rio_cnt<0)
    {
      if(errno!=EINTR)
         return -1;
    }
    else if(rp->rio_cnt==0)
        return 0;
    else 
      rp->rio_bufptr=rp->rio_buf;
  }
  cnt=n;
  if(rp->rio_cnt<n)
      cnt=rp->rio_cnt;
  memcpy(usrbuf,rp->rio_bufptr,cnt);
  rp->rio_bufptr+=cnt;
  rp->rio_cnt-=cnt;
  return cnt;
}
ssize_t rio_readlineb(rio_t* rp,void *usrbuf,size_t maxlen)
{
  int n,rc;
  char c;
  char* bufp=usrbuf;
  for(n=1;n<maxlen;n++)
  {
    if((rc=rio_read(rp,&c,1))==1)
    { 
      *bufp++=c;
      if(c=='\n')
         break;
     }
    else if(rc==0)
    {
    if(n==1)
      return 0;
    else
     break;
    }
    else
    return -1;
  }
*bufp=0;
return n;
}
ssize_t rio_readnb(rio_t* rp,void* usrbuf,size_t n)
{
  size_t nleft=n;
  ssize_t nread;
  char* bufp=usrbuf;
  while(nleft>0)
  {
    if((nread=rio_read(rp,bufp,nleft))<0)
    {
      if(errno==EINTR)
        nread=0;
      else
        return -1;
    }
    else if(nread==0)
      break;
    nleft-=nread;
    bufp+=nread;
  }
  return (n-nleft);
}

ssize_t rio_readn(int fd,void* usrbuf,size_t n)
{
  size_t nleft=n;
  ssize_t nread;
  char* bufp=usrbuf;
  while(nleft>0)
  {
    if((nread=read(fd,bufp,nleft))<0)
    {
      if(errno==EINTR)
        nread=0;
      else
        return -1;
    }
    else if(nread==0)
      break;
    nleft-=nread;
    bufp+=nread;
  }
  return (n-nleft);
}
ssize_t rio_writen(int fd,void* usrbuf,size_t n)
{
  size_t nleft=n;
  ssize_t nwriten;
  char* bufp=usrbuf;
  while(nleft>0)
  {
    if((nwriten=write(fd,bufp,nleft))<=0)
       {
         if(errno==EINTR)
           nwriten=0;
         else
           return -1;
       }
      nleft-=nwriten;
      bufp+=nwriten;
  }
  return n;
}
int open_listenfd(int port)
{
  int listenfd,optval=1;
  struct sockaddr_in serveraddr;
  
  if((listenfd=socket(AF_INET,SOCK_STREAM,0))<0)
     return -1;
  if(setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,(const void*)&optval,sizeof(int))<0)
     return -1;
  bzero((char*)&serveraddr,sizeof(serveraddr));
  serveraddr.sin_family=AF_INET;
  serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
  serveraddr.sin_port=(htons((unsigned short)port));
  if(bind(listenfd,(SA*)&serveraddr,sizeof(serveraddr))<0)
     return -1;
  if(listen(listenfd,LISTENQ)<0)
     return -1;
  return listenfd;
}

void init_pool(int listenfd,pool* p)
{
  int i;
  p->maxi=-1;

  for(i=0;i<FD_SETSIZE;i++)
    p->clientfd[i]=-1;
  
  p->maxfd=listenfd;
  FD_ZERO(&p->read_set);
  FD_SET(listenfd,&p->read_set);
}

void add_client(int connfd,pool* p)
{
  int i;
  p->nready--;
  for(i=0;i<FD_SETSIZE;i++)
   if(p->clientfd[i]<0)
   {

     p->clientfd[i]=connfd;
     rio_readinitb(&p->clientrio[i],connfd);

     FD_SET(connfd,&p->read_set);

     if(connfd>p->maxfd)
        p->maxfd=connfd;
     if(i>p->maxi)
        p->maxi=i;
     break;
   }
  if(i==FD_SETSIZE)
    fprintf(stderr,"error i>=FD_SETSIZE\n");
}
int MSquery(int sock,char* msg,MYSQL* mysql)
{

   char query[MAXQUERY];
   char send[MAXLIEN];
   char* p=send;
   MYSQL_RES* result;
   MYSQL_ROW row;
   int num;
   int i;

   sprintf(query,"SELECT * FROM MSbook WHERE name='%s'",msg);
    printf("query=%s\n",query);
   if(!mysql_query(mysql,query))
   {
         result=mysql_store_result(mysql);
      if(!result)
       {
         write(sock,"NOT",4);
         mysql_free_result(result);
         return 1;
       }
   }
  num=mysql_num_fields(result);
  if((row=mysql_fetch_row(result))!=NULL)
  {
     
        for(i=0;i<num;i++){ 
         sprintf(p,"%s\t",row[i]);
         p+=(strlen(row[i])+1);
       }
      write(sock,send,strlen(send));

  }
  else
  {
	  write(sock,"NOT",4);
	  mysql_free_result(result);
          return 1;
  }
    mysql_free_result(result);
  return 0;
}
int MSdelete(int sock,char* msg,MYSQL* mysql,char* tables)
{
       char query[MAXQUERY];
       sprintf(query,"DELETE FROM %s WHERE name='%s'",tables,msg);
       printf("query=%s\n",query);
       if(!mysql_query(mysql,query))
       {    if(mysql_affected_rows(mysql)>0)
             {
                 write(sock,"OK",3);
                 return 0;  
              }
             else{
               write(sock,"NOT",4);
	       return 1;
          }
       }                                   
      
          
}
int MSinsert(int sock,char* msg,MYSQL* mysql,char* tables)
{
    char query[MAXQUERY];
    char *p=msg;
    p=strchr(p++,'>');
    *p=0;
   sprintf(query,"INSERT INTO %s values(%s)",tables,msg+1);
   printf("query=%s\n",query);
   if(mysql_query(mysql,query))
   {    
        write(sock,"NOT",4);
	return 1;
     
   }                                   
    write(sock,"OK",3);
    return 0;          
}
void check_clients(pool* p,MYSQL* BKmysql)
{
  int i,connfd,n;                       
  char* top;
  char ch;
  char buf[MAXLIEN];
  char MSmsg[MAXLIEN];
  rio_t rio;
  for(i=0;(i<=p->maxi)&&(p->nready>0);i++)
  {
    connfd=p->clientfd[i];
    rio=p->clientrio[i];
    if((connfd>0)&&(FD_ISSET(connfd,&p->ready_set))){
      p->nready--;
      if((n=rio_read(&rio,buf,MAXLIEN))!=0)
      {
        
	      top=strchr(buf,':');
              ch=*(top+1);
		 top=strchr(top+1,':');
		 *top=0;
		 strcpy(MSmsg,buf+4);
		 switch(ch)
		 {
			 case '1':
				 MSquery(connfd,MSmsg,BKmysql);
				 break;
			 case '2':
                                 MSinsert(connfd,MSmsg,BKmysql,"MSbook");
                                 break;
			 case '3':
                                 MSdelete(connfd,MSmsg,BKmysql,"MSbook");
                                 break;
                         case '4':
                                 MSinsert(connfd,MSmsg,BKmysql,"MSuser");
                         case '5':
                                 MSdelete(connfd,MSmsg,BKmysql,"MSuser");
                                 
		 };

      }
      else
      {
        close(connfd);
        FD_CLR(connfd,&p->read_set);
        p->clientfd[i]=-1;
      }
    }
  }
}


int login(int sock,MYSQL* usermysql,char* user)
{
    char userbuf[MAXLIEN];
    char username[MAXNAME];
    char userpwd[MAXPWD];
    char query[MAXQUERY];
    MYSQL_ROW row;
    MYSQL_RES *result;
    unsigned int num_fields;
    unsigned int i;
    char* top;
    read(sock,userbuf,MAXLIEN);                 //(user password)
     top=strchr(userbuf,'(');
     *top=0;
     top=strchr(userbuf+1,')');
     *top=0;
     top=strchr(userbuf+1,',');
     *top=0;
     strcpy(username,userbuf+1);
     strcpy(userpwd,top+1);
     strcpy(user,username);
     sprintf(query,"SELECT password FROM MSuser where name='%s'",username);
     if(!mysql_query(usermysql,query)){
        result = mysql_store_result(usermysql);
        if(!result){
            write(sock,"NOT",4);
           return 1;
        }
     }
     if((row = mysql_fetch_row(result))!=NULL&&strcmp(row[0],userpwd)==0){
           write(sock,"OK",3);
           mysql_free_result(result);
           return 0;}
    else{
          write(sock,"NOT",4);
          mysql_free_result(result);
          return 1;
}
}

