#include <stdio.h>
#include <stdlib.h>

void sump(int *a,int size,int k)
{
   int i=0;
   int j=size;

   while(i!=j)
       if((a[i]+a[j])==k){
           printf("%d,%d\n",a[i],a[j]);
           break;}
       else if((a[i]+a[j])<k)
           i++;
        else
           j--;
}
int main(int argc,char** argv)
{
 int a[]={1,2,4,7,11,15};

  sump(a,5,15);


    exit(0);
}

