/*************************************************************************
    > File Name: time.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年04月27日 星期三 20时06分28秒
 ************************************************************************/
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
int main(int argc,char** argv)
{
   
   time_t i;

   time(&i);
   printf("%d\n",i);







	exit(0);
}
