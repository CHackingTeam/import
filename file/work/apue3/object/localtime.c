/*************************************************************************
    > File Name: localtime.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年04月27日 星期三 20时52分30秒
 ************************************************************************/
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#define MAXSIZE 64
int main(int argc,char* argv[])
{
    
    time_t tim;
	struct tm* tp;
	char buf[MAXSIZE];
	time(&tim);
    tp=localtime(&tim);
   if(strftime(buf,MAXSIZE,"%c",tp)==0)
	   perror("error buf maxsize 64 byte");
   else
    printf("%s\n",buf);






	exit(0);
}
