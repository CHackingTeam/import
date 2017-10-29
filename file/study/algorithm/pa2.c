/*************************************************************************
    > File Name: paixu.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年04月26日 星期二 10时53分16秒
 ************************************************************************/
#include <stdio.h>
int pa_(int *a,int l,int r);

void pa(int* a,int l,int r)
{
int i;
  if(l<r)
  {
    i=pa_(a,l,r);
	pa(a,l,i-1);
	pa(a,i+1,r);
  }
}
int pa_(int *a,int l,int r)
{
    int j=l;
	int i;
	int h;
	for(i=l+1;i<=r;i++)
	{  
        if(a[i]<=a[l]) 
		{
		  j++;
          h=a[i];
		  a[i]=a[j];
		  a[j]=h;
		  
        }
    }
    a[l]^=(a[j]);
	a[j]^=(a[l]);
	a[l]^=(a[j]);



   return j;
}




int main(int argc,char** argv)
{
  int i=0;
  int a[]={
	  1,2,34,4,3
  };

 pa(a,0,4);
 

  for(;i<5;i++)
	printf("%d\n",a[i]);




	return 0;
}
