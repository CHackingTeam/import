#include <stdio.h>
int* p;
int i;
void debug(int c)
{
  printf("%d\n",&c);
  
  char a[4];
  printf("%d\n",&a);
//  p=(int*)&a;
  for(i=0;i<4;i++)
     a[i]='c';
 // p=p+2;
 // (*p)=(*p)+1;
}
int main(int argc,char* argv[])
{
 int f=0;
 int c=4;
 debug(c);
 
 c=5;
 f=7;
 printf("%d\n",c);



return 0;
}


