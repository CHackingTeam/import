/*************************************************************************
    > File Name: dg_cli.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年04月24日 星期日 09时15分48秒
 ************************************************************************/
#include "unp.h"
void dg_cli(FILE* filep,int sockfd,const SA* pservaddr,socklen_t len)
{
   
	char send[MAXLINE],recv[MAXLINE];
	int n;
   while(Fgets(send,MAXLINE,filep)!=NULL)
   {
    Sendto(sockfd,send,strlen(send),0,pservaddr,len);
	n=Recvfrom(sockfd,recv,MAXLINE,0,NULL,NULL);
	recv[n]=0;
	fputs(recv,stdout);
   }





}
