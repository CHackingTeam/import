/*************************************************************************
    > File Name: udpcli.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年04月24日 星期日 09时03分58秒
 ************************************************************************/
#include "unp.h"
int main(int argc,char* argv[])
{
    int sockfd;
	struct sockaddr_in cliaddr;
	sockfd=Socket(AF_INET,SOCK_DGRAM,0);
	bzero(&cliaddr,sizeof(cliaddr));
	cliaddr.sin_port=htons(SERV_PORT);
    cliaddr.sin_family=AF_INET;
	Inet_pton(AF_INET,argv[1],&cliaddr.sin_addr);
	dg_cli(stdin,sockfd,(SA*)&cliaddr,sizeof(cliaddr));

		
		
  



	exit(0);
}
