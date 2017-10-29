/*************************************************************************
    > File Name: main.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年04月14日 星期四 20时58分10秒
 ************************************************************************/

#include <stdio.h>
int  debug(int c)
{
  char a[]="hello kail linux";
  int i;
  int* p=&c;
  char* ap=a;
  for(i=0;i<16;i++)
	printf("a[]=%x\n",a[i]);
   p+=15;
   (*p)=0x4005ef;
   printf("c:\t%x\n",p);
   printf("ap:\t%x\n",ap);
   i=p-2;
   i=p-4;

  return 0;
}
int main(int argc,char* argv[])
{
   int c=4;
   printf("c=%d\t\n",c);
   debug(c);
   int f=5;
   c=5;
   printf("c=%d\t\n",c);
   //printf("%d\n",sizeof(int));




	return 0;
}
