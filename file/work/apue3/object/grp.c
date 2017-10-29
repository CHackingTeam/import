/*************************************************************************
    > File Name: grp.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年04月26日 星期二 21时30分07秒
 ************************************************************************/
#include <grp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char** argv)
{
   int i=getgroups(0,NULL);
   printf("%d\n",i);
   int c;
   gid_t group[i];
   group[0]=1;
   getgroups(1,group);
   for(c=0;c<=i;c++)
	 printf("%d\t",group[c]);






	exit(0);
}
