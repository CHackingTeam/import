/*************************************************************************
    > File Name: udpserv.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年04月24日 星期日 08时43分31秒
 ************************************************************************/
#include "unp.h"
int main(int argc,char* argv[])
{
  int sockfd;
  struct sockaddr_in servaddr,cliaddr;
  sockfd=Socket(AF_INET,SOCK_DGRAM,0);
  bzero(&servaddr,sizeof(struct sockaddr_in));
  servaddr.sin_family=AF_INET;
  servaddr.sin_port=htons(SERV_PORT);
  servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
  Bind(sockfd,(SA*)&servaddr,sizeof(servaddr));
  dg_echo(sockfd,(SA*)&cliaddr,sizeof(cliaddr));




	exit(0);
}
