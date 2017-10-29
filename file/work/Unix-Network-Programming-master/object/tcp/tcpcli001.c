#include	"unp.h"
#include <signal.h>
 #include <sys/time.h>
#include <sys/select.h>
#include <unistd.h>
#include <sys/types.h>
void
str_cli(FILE *fp, int sockfd)
{
	char			 sendline[MAXLINE];
        char                     send_addrline[MAXLINE];
        char                     recvline[MAXLINE];
        int  n;
        ssize_t  n2; 
        fd_set read,ready;
        FD_ZERO(&ready);
       
        FD_SET(fileno(fp),&ready);
        FD_SET(sockfd,&ready);
        char c[4]={'n'};
      struct sockaddr_in sa;
      int len=sizeof(sa);
       getsockname(sockfd,(struct sockaddr*)&sa,&len);

	
       for(;;) {

         
               read=ready;
               n=select(sockfd+1,&read,NULL,NULL,NULL);
          
           if(FD_ISSET(fileno(fp),&read))
          {


                if(Fgets(sendline, MAXLINE, fp) != NULL)
                 {
                sprintf(send_addrline,"%s:%s",inet_ntoa(sa.sin_addr),sendline);
                printf("Write sockfd\n");               
          
	        Writen(sockfd,c,1);
 
                }
               }

            if(FD_ISSET(sockfd,&read))
           {
                
	        if (Readn(sockfd,recvline,1)== 0)
			err_quit("str_cli: server terminated prematurely");
                 


             printf("\t\tserver:\t%s\n",recvline);
          }



	}
	
}

void handler(int sig)
{

printf("SIGPIPE\n");




}

int
main(int argc, char **argv)
{
	int					sockfd;
	struct sockaddr_in	servaddr;
  
         signal(SIGPIPE,handler);
	if (argc != 2)
		err_quit("usage: tcpcli <IPaddress>");
      
	sockfd= Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    
	Connect(sockfd, (SA *) &servaddr, sizeof(servaddr));
    
        
	str_cli(stdin, sockfd);		/* do it all */

	exit(0);
}
