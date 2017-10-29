#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libMS.h"
int main(int argc, char **argv)
{

	int					sockfd, n, counter = 0;
	char				buf[MAXLINE + 1];
	char                user_password[MAXLINE+1];
	char                logtimebuf[MAXLINE+1];
	struct sockaddr_in	servaddr;
	time_t logtime;
	struct tm* tmp;
    

	if (argc != 2)
		fprintf(stderr,"usage: a.out <IPaddress>");

	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		fprintf(stderr,"socket error");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port   = htons(1024);	
	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
		fprintf(stderr,"inet_pton error for %s", argv[1]);

	if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
		fprintf(stderr,"connect error");

    printf("Enter admin and password (user,password)\n");
    scanf("%s",user_password);
    write(sockfd,user_password,strlen(user_password));
	read(sockfd,buf,MAXLINE);
	if(strcmp(buf,"OK")){
		printf("password or user error\n");
		exit(0);
	}
	else
	{
           time(&logtime);
	   tmp=localtime(&logtime);
	   strftime(logtimebuf,64,"last login time: %r,%a,%b,%d,%Y",tmp);
	   printf("%s\n",logtimebuf);

	}
	MSprint();
    do
	{
       int n=1;
	   printf("switch number:");
	   //scanf("%d",&n);
           if(n<1||n>9){
	       printf("error number\n");
	       continue;
	   }

	   switch(n)
	   {
                case 1:
                   MSsearch(sockfd);
		   break;
		case 2:
		   MSaddBK(sockfd);
		   break;
		case 3:
		   MSdeleteBK(sockfd);
		   break;
                 case 4:
                   MSadduser(sockfd);
                   break;
                 case 5:
                   MSdeleteuser(sockfd);
                    break;
		case 9:
            close(sockfd);    
			exit(0);

	   }

	}while(1);

	exit(0);
}
