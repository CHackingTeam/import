#include <stdio.h>
#include <stdlib.h>
int main(int argc,char* argv[])
{

  double a=0.5;
  int i;
 unsigned int *p=(unsigned int*)&a;



 if(-1<0U)
   printf("-1<0\n");
  //for(i=0;;i++)
 // {
   // a=(float)i;
//for(i=0;i<4;i++)
  printf("g1=%d\tg2=%lf\n",*(p),a);
 // }


  return 0;
}
