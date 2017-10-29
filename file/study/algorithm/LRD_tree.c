#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf j;

int assert_LRD_CH(int* a,int left,int i)
{
 while(a[left]<a[i]) left++;

 if(left==i)
     return 1;
 else
     return 0;
}
void move(int* a,int i,int right)
{  
  int c=a[right];
  while(right!=i)
      a[right]=a[right-1],right--;

a[i]=c;

}

void assert_LRD(int *a,int left,int right)
{

if(left<right)
{
   int i=right-1;
   int c;
   while(a[right]<a[i])
       i--;
   i++;
   move(a,i,right);
    assert_LRD(a,left,i-1);
    assert_LRD(a,i+1,right);
   if(!assert_LRD_CH(a,left,i))
        longjmp(j,1);
}

}
int LRD(int *a,int left,int right)
{
  int c=1;
if(!setjmp(j)||--c)
  assert_LRD(a,left,right);
 if(c==0)
     return 0;
 else
     return 1;
}

int main(int argc,char** argv)
{

    int arr_tree[]={7,4,6,5};

    printf("%d\n",LRD(arr_tree,0,3));

    
    exit(0);
}
