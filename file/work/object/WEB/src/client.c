#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1024
#define BUFSIZE 8912
typedef struct sockaddr SA;
char* p[]={"GET /cgi-bin/adder?67&89\n","GET /cgi-bin/adder?9210&374\n","GET /cgi-bin/adder?89324&83249\n"};



int main(int argc, char **argv)
{
	int					sockfd, n,i=0, counter = 0;
	char				bufarg[MAXLINE];
  char        bufstr[BUFSIZE];
	struct sockaddr_in	servaddr;
  
	if (argc != 2)
		fprintf(stderr,"usage: a.out <IPaddress>");
  while(1){
	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
 		fprintf(stderr,"socket error");
  
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port   = htons(1024);	/* daytime server */
	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
		fprintf(stderr,"inet_pton error for %s", argv[1]);
 

  printf("Trying:%s...\n",argv[1]);
  

  if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
		fprintf(stderr,"connect error");
   
   printf("Connected to %s...\n",argv[1]);
  
   if(i==3)
     i=0;

   sprintf(bufarg,p[i]);
 //  sprintf(bufarg,"\n");

   i++;

   //fgets(buf,MAXLINE,stdin);
   write(sockfd,bufarg,strlen(bufarg));
  
   sprintf(bufarg,"\r\n");
   write(sockfd,bufarg,strlen(bufarg));

   while((n=read(sockfd,bufstr,MAXLINE))>0)
   {
     bufstr[n]=0;
      if(fputs(bufstr,stdout)==EOF)
          fprintf(stderr,"fputs error");
   }
   if(n<0)
      fprintf(stderr,"read error");

     printf("counter:\t%d\n",counter);
     counter++;

}


   


  /*
	while ( (n = read(sockfd, recvline, MAXLINE)) > 0) {
		counter++;
		recvline[n] = 0;	
		if (fputs(recvline, stdout) == EOF)
			fprintf(stderr,"fputs error");
	}
	if (n < 0)
		fprint("read error");

	printf("counter = %d\n", counter);
  */
	exit(0);
}
