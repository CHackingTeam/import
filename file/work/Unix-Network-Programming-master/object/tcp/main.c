/*************************************************************************
    > File Name: mian.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年06月03日 星期五 21时37分26秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "unp.h"
extern char** environ;
int main(int argc,char** argv)
{
   
	char* arg[]={
		"client","127.0.0.1",NULL
	};

	int i=0;
	for(;i<1;i++)
	{
		printf("%d\n",i);
		if(fork()==0)
	 	{
           execve("./client",arg,environ);
	//	   system("./client 127.0.0.1");
         // system("gnome-terminal -x ./client 127.0.0.1");
           printf("exit()\n");
		   exit(0);
		}

		
	}

	wait(NULL);
	exit(0);
}
