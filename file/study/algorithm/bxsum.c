#include <stdio.h>
#include <stdlib.h>
#define MAXBIT 31

int bitsum(int c)
{
  int sum=0;
  int i=MAXBIT;
  while(i!=-1){
      if(c&(1<<i))
              sum++;
      i--;
      }
   return sum;

}

int main(int argc,char** argv)
{
   int c=3424234;
   printf("%d\n",bitsum(c));
    exit(0);
}

