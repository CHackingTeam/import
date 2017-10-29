/*************************************************************************
    > File Name: clock_gettime.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年04月27日 星期三 20时30分08秒
 ************************************************************************/
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char** argv)
{
     
   struct timespec time_i;
   clock_gettime(CLOCK_REALTIME,&time_i);
   printf("sec:%d\tnsec:%d\n",time_i.tv_sec,time_i.tv_nsec);
   clock_gettime(CLOCK_MONOTONIC,&time_i);
   printf("sec:%d\tnsec:%d\n",time_i.tv_sec,time_i.tv_nsec);

   




	exit(0);
}
