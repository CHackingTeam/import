/*************************************************************************
    > File Name: strptime.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年04月27日 星期三 21时11分03秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#define MAXSIZE 64
int main(int argc,char* argv[])
{  


	time_t tim;
	struct tm* tp;
	struct tm tp2;
  //	tp2=(struct tm*)malloc(sizeof(struct tm));
    char buf[MAXSIZE];
	time(&tim);
	tp=localtime(&tim);
    if(strftime(buf,MAXSIZE,"%c",tp)==0)
	   perror("error buf maxsize 64 byte");
	else
	   printf("%s\n",buf);

    if(strptime(buf,"%c",&tp2)==NULL)
	  perror("error ");
	else
      printf("year:%d\n",tp2.tm_year);
      printf("hour:%d\n",tp2.tm_hour);
	  printf("min:%d\n",tp2.tm_min);







	exit(0);
}
