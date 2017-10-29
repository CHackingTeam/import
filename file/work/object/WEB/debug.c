/*************************************************************************
    > File Name: debug.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年05月25日 星期三 07时56分46秒
 ************************************************************************/
#include <stdio.h>
#define MAX 1024
int main()
{
char s1[MAX];
char s2[MAX];
char s3[MAX];
char* s4=s1;
char s[]="hi hack !!!";

sscanf(s,"%s %s %s",s1,s2,s3);
//printf("%s,%s,%s",s1,s2,s3);
for(;*s4!=0;s4++)
  printf("%c\n",*s4);





	return 0;
}
