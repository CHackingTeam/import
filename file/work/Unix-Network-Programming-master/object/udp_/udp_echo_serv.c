/*************************************************************************
    > File Name: udp_echo_serv.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年05月15日 星期日 08时18分37秒
 ************************************************************************/
#include "unp.h"
void dg_echo(int sockfd,SA* addr,socklen_t len)
{
   
	int n;
	socklen_t l;
	char mseg[MAXLINE];

	while(1)
	{
        l=len;
     n=recvfrom(sockfd,mseg,MAXLINE,0,addr,&l);
     printf("reply from %s (ignored)\n",sock_ntop(addr,l));
	 sendto(sockfd,mseg,n,0,addr,l);

    }



}
