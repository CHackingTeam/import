#include <stdio.h>
int main(int argc,char* argv[])
{

int c;
int* p=&c;
int d=(int)p;
char* v=(char*)&p;
/*for(c=0;c<sizeof(int*);c++)
  printf("%d\n",v[c]);*/
if(p>0)
  printf("p>0\n");
if(d>0)
  printf("p>0\n");

if(-1<0u)
  printf("no error\n");



printf("%u\t%x\n",d,p);







  return 0;
}
