#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1024

typedef struct sockaddr SA;

int main(int argc, char **argv)
{
	int					sockfd, n, counter = 0;
	char				buf[MAXLINE + 1];
	struct sockaddr_in	servaddr;

	if (argc != 2)
		fprintf(stderr,"usage: a.out <IPaddress>");

	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		fprintf(stderr,"socket error");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port   = htons(1024);	/* daytime server */
	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
		fprintf(stderr,"inet_pton error for %s", argv[1]);

	if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
		fprintf(stderr,"connect error");


  do{
         fgets(buf,MAXLINE,stdin);
         if(!strcasecmp(buf,"exit\n"))
            break;
        write(sockfd,buf,strlen(buf));
       if((n= read(sockfd,buf,MAXLINE))<0)
           fprintf(stderr,"error read\n");
        fputs(buf,stdout);
      }while(1);


    close(sockfd);

  /*
	while ( (n = read(sockfd, recvline, MAXLINE)) > 0) {
		counter++;
		recvline[n] = 0;
		if (fputs(recvline, stdout) == EOF)
			fprintf(stderr,("fputs error");
	}
	if (n < 0)
		("read error");

	printf("counter = %d\n", counter);
  */
	exit(0);
}
