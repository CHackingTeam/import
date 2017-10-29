/*************************************************************************
    > File Name: objdump.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年05月18日 星期三 07时56分04秒
 ************************************************************************/
#include "unp.h"
#include <time.h>
#define LEFT(left) ((left)&15)
#define HIGHT(hight) (((hight)&240)>>4)

int main()
{
    char* p;
	char* p2;
	
	char str[]="hi kail linux";
	p=str;
	p2=p;
	int i=0;
    int c;
	for(;i<1024*1024;i++)
	{
      printf("%x%x",LEFT(*p),HIGHT(*p));
	  printf(" ");
	  

	  fflush(stdout);
	  sleep(0.5);
	  if((i%20)==0){
		  printf("     ");
       for(c=0;c<20;c++)
		  {
           printf("%c",*p2);
	  	   p2++;

		  }
		  printf("\n");
   

	  }
	  p++;

	}
	printf("\n");
//	system("objdump -d out");
/*
	int x=255;
	printf("%x\n",LEFT(x));
	printf("%x\n",HIGHT(x));
*/
	exit(0);
}
