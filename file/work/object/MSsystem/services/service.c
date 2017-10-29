#include "libMS.h"
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/select.h>
MYSQL MSmysql;

int main(int argc,char* argv[])
{
  int listenfd,connfd,port;
  socklen_t  clientlen=sizeof(struct sockaddr_in);
  struct sockaddr_in clientaddr;
  static pool pool;
  char username[MAXNAME];
  time_t logtime;
  struct tm* tmp;
  char logtimebuf[1024];
  mysql_init(&MSmysql);
 if(!mysql_real_connect(&MSmysql,HOST,USERNAME,PASSWORD,DATABASE,0,NULL,0))
	 printf("Connection failed,%s\n",mysql_error(&MSmysql));
 mysql_query(&MSmysql,"set names utf8");

  if(argc!=2)
  {
    fprintf(stderr,"usage: %s <port>\n",argv[0]);
    exit(0);
  }
  port=atoi(argv[1]); 
  listenfd=open_listenfd(port);
  init_pool(listenfd,&pool);

  while(1)
  {
    pool.ready_set=pool.read_set;
    pool.nready=select(pool.maxfd+1,&pool.ready_set,NULL,NULL,NULL);

    if(FD_ISSET(listenfd,&pool.ready_set)){
      connfd=accept(listenfd,(SA*)&clientaddr,&clientlen);
      if(login(connfd,&MSmysql,username))
          printf("login:%s  status:failed\n",username);          //ip =????
      else{   
          add_client(connfd,&pool);
	     time(&logtime);
	     tmp=localtime(&logtime);
	     strftime(logtimebuf,64,"%r,%a,%b,%d,%Y",tmp);
          printf("login:%s  status:Successful  time:%s\n",username,logtimebuf); 
          }           
    }

    check_clients(&pool,&MSmysql);
  }

  exit(0);
}

