#include <stdio.h>
#include <stdlib.h>

int gcd(int m,int n)
{
  while(n!=0)
  {
    int t=m%n;
    m=n;
    n=t;
  }

return m;
}
int main(int argc,char** argv)
{

   printf("%d\n",gcd(50,15));


    exit(0);
}
