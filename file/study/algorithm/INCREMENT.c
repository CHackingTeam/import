#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_BIT 31


int a[MAX_BIT];

void INCREMENT(int *a)
{
   int i=0;
   while(i<=MAX_BIT&&a[i]==1)
       a[i]=0,i+=1;
   if(i<=MAX_BIT)
       a[i]=1;
}
void print(int *a)
{
    int i=0;
   while(i!=(MAX_BIT+1))
       printf("%d  ",a[i]),i++;
   printf("\n");

}
void printt()
{
 //srand((unsigned)time(NULL));
 int i=rand()%4;
 for(int j=0;j<i;j++)
     printf("\t");
}
void printn()
{

 // srand((unsigned)time(NULL));

  int i=rand()%4;
  for(int j=0;j<i;i++)
      printf("\n");

}
int main(int argc,char** argv)
{
    int i=0;
/*
   for(int i=0;i<32;i++)
       a[i]=0;

while(1)
{
INCREMENT(a);
print(a);
}
*/


while(1)
{
    printt();
    printn();
    i=rand()%2;
    printf("%d",i);


}


    exit(0);
}
