/*************************************************************************
    > File Name: udp_dg_cli.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年05月15日 星期日 07时47分20秒
 ************************************************************************/
#include "unp.h"
void dg_cli(FILE* fp,int sockfd,const SA* addr,socklen_t sockaddrlen)
{
 
    connect(sockfd,(SA*)addr,sockaddrlen);
	int n;
	char sendline[MAXLINE],recvline[MAXLINE];
	while(fgets(sendline,MAXLINE,fp)!=NULL)
	{
		/*
       sendto(sockfd,sendline,strlen(sendline),0,addr,sockaddrlen);
	   n=recvfrom(sockfd,recvline,MAXLINE,0,NULL,NULL);*/
       
	  write(sockfd,sendline,strlen(sendline));
	  read(sockfd,recvline,MAXLINE);

	   recvline[n]=0;
	   fputs(recvline,stdout);

	   
  

	}

}

