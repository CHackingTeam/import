#include	"unp.h"
#include <unistd.h>
#define  FD_SIZE 100

typedef void (*funptr)(int);


void
str_echo(int sockfd)
{
	char sendline[MAXLINE];
        char recvline[MAXLINE];
        char send_addrline[MAXLINE];
      
        ssize_t n;
        
         struct sockaddr_in sa;
         int len=sizeof(sa);
         getsockname(sockfd,(struct sockaddr*)&sa,&len);

	for ( ; ; ) {
       
                 
		if ( (n = Readn(sockfd,recvline,sizeof(recvline))) == 0)
			return;
                 
                 printf("\t\tclient:\t%s\n",recvline);
                 if((Fgets(sendline,sizeof(sendline),stdin))==NULL)
                                  break;   
                                
                sprintf(send_addrline,"%s:%s",inet_ntoa(sa.sin_addr),sendline); 
                 Writen(sockfd,send_addrline,sizeof(send_addrline));     
           //   sleep(10);    
               //  Writen(sockfd,send_addrline,sizeof(send_addrline));
         
	}
}

void sig_ch(int sigch)
{
	pid_t	pid;
	int		stat;
        static int count=1;

   while((pid = waitpid(-1,&stat,WNOHANG))>0)
{
     printf("child %d terminated\n", pid);
}
	return;
}
void sig_pipe(int sigpipe)
{  
      
printf("pipe\n");

  return;
  
}
int main(int argc, char **argv)
{
        funptr p=    sig_ch;
        funptr p2=   sig_pipe;
	int					listenfd, connfd,sockfd;
	pid_t				childpid;
	socklen_t			clilen;
	struct sockaddr_in	cliaddr, servaddr;
        int client[FD_SIZE];
        int maxi;
        int maxfd;
        int i;
        fd_set read,ready;
        int nread;
        int n;
        char buf[MAXLINE];
	listenfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port        = htons(SERV_PORT);

	Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));
 
	Listen(listenfd, LISTENQ);
        signal(SIGCHLD,p);
        signal(SIGPIPE,p2);

        for(i=0;i++;i<FD_SIZE)
            client[i]=-1;
        
        //client[0]=listenfd;
        FD_ZERO(&read);
        FD_SET(listenfd,&read);
        clilen=sizeof(cliaddr);
        maxi=-1;
        maxfd=listenfd;

    for(;;)
   {   

       ready=read;
 
        nread=select(maxfd,&ready,NULL,NULL,NULL);
       
        if(FD_ISSET(listenfd,&ready))
          {
          connfd=Accept(listenfd,(SA*)&cliaddr,&clilen);
           for(i=1;i++;i<FD_SIZE)
             if(client[i]<0)
               {
                client[i]=connfd;
                break;
                }
            if(i==FD_SIZE)
             perror("i=FD_SIZE");
           
		if(connfd>maxfd)
                   maxfd=connfd;
	      	if(i>maxi) 
                   maxi=i;
                 FD_SET(connfd,&read);
               if(--nread<=0)
                  continue;
          }
	for (i = 0; i <= maxi; i++) {	/* check all clients for data */
			if ( (sockfd = client[i]) < 0)
				continue;
			if (FD_ISSET(sockfd, &ready)) {
				if ( (n = Read(sockfd, buf, MAXLINE)) == 0) {
						/*4connection closed by client */
					Close(sockfd);
					FD_CLR(sockfd, &read);
					client[i] = -1;
				} else
					Writen(sockfd, buf, n);

				if (--nread<= 0)
					break;				/* no more readable descriptors */
			}
		}         
}
return 0;

}














