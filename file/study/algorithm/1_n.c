#include <stdio.h>
#include <stdlib.h>

int s=0;

int sum(int n)
{
   s+=n;
   return (n-1)&&sum(n-1);
}

int main(int argc,char** argv)
{
   sum(100);
   printf("%d\n",s);
    exit(0);
}


