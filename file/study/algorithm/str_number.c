#include <stdio.h>
#include <stdlib.h>
#define NO_NUM -1

int assert_number(char* str)
{ 
 int sum=0;
 char *p=str;
 while(*p!=0&&*str!='0'&&'0'<=*p&&*p<='9')
           sum=sum*10+(*p-('0'-0)),p++;
 return sum;
}
int main(int argc,char** args)
{
  
 printf("%d\n",assert_number("1024"));


    exit(0);
}
