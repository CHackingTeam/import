#include <stdio.h>
#include <stdlib.h>
#define PARENT(x)   x/2
#define LEFT(x)  2*x
#define RIGHT(x) 2*x+1


void heap_ch(int *a,int i,int size)
{ 
  int l=LEFT(i);
  int r=RIGHT(i);
  int p;
  if(l<=size&&a[i]<a[l])
	  p=l;
  else
	  p=i;
  if(r<=size&&a[p]<a[r])
	  p=r;
  if(p!=i)
  {
    int c=a[i];
	a[i]=a[p];
	a[p]=c;
	heap_ch(a,p,size);
  }

}
void heap_buile(int *a,int size)
{

   for(int c=size/2;c!=0;c--)
      heap_ch(a,c,size);
}
void heap_sqrt(int *a,int size)
{
	if(size!=2)
	{
    printf("%d\t",a[1]);
	a[1]=a[size];
	size--;
	heap_ch(a,1,size);
	heap_sqrt(a,size);

	}

}
int main(int argc,char** argv)
{

int a[]={0,1,5,3,7,2,8};

heap_buile(a,6);
for(int i=0;i<7;i++)
	printf("%d\t",a[i]);
printf("\n");
heap_sqrt(a,6);
printf("%d\t%d\n",a[1],a[2]);
	exit(0);
}
