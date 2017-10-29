/*************************************************************************
    > File Name: hostnet.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年05月17日 星期二 21时20分04秒
 ************************************************************************/
#include <stdio.h>
#include "unp.h"
int main(int argc,char* argv[])
{
    
	if(argc!=2)
	   perror("argc error");
	struct hostent* phost;
        char **list;
	char* p;
	char str[INET_ADDRSTRLEN];
	if((phost=gethostbyname(argv[1]))==NULL)
	   printf("error gethostbyname\t%s\n",hstrerror(h_errno));
	
    printf("host name:\n\t%s",phost->h_name);
	printf("\nname:");
	list=phost->h_aliases;
	for(;*list!=NULL;list++)
	    printf("\n\t%s",*list);
	if(phost->h_addrtype==AF_INET)
	   {  
		   printf("\nIPV4:\t\n");
           list=phost->h_addr_list;
		   for(;*list!=NULL;list++)
			    printf("\t%s\n",inet_ntop(phost->h_addrtype,*list,str,sizeof(str)));
        }



	return 0;
}
