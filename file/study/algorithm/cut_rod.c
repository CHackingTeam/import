#include <stdio.h>
#include <stdlib.h>

#define MAX(x,y) ((x)>(y)?(x):(y))
int dp[]={0,1,5,8,9,10,17,17,20,24,30};
int CUT_ROD(int *p,int n)
{
int q;    
if(n==0)
    return 0;
q=-10000;

for(int i=1;i<=n;i++)
  q=MAX(q,p[i]+CUT_ROD(p,n-i));
return q;

}
int main(int argc,char** argv)
{

printf("CUT_ROD(4)=%d\n",CUT_ROD(dp,4));

    exit(0);
}
