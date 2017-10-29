#include <stdio.h>
#include <stdlib.h>

void arryc(int i,int j,int* arry)
{
   int a=arry[j];
   for(int n=j;n>i;n--)
         arry[n]=arry[n-1];
arry[i]=a;
}

void insert_sqrt(int *arry,int size)
{
   
   for(int i=0;i<size;i++)
	   for(int j=0;j<=i;j++){
		   if(arry[i]<arry[j]){
			   arryc(j,i,arry);
               break;
		   }
	   }

}


int main(int argc,char** argv)
{
  
int a[]={
	  5,3,9,1,4,0,5
  };

insert_sqrt(a,7);

for(int i=0;i<7;i++)
	printf("%d\t",a[i]);

printf("\n");

	exit(0);
}
