#include <stdio.h>
#include <stdlib.h>
int main(int argc,char* argv[])
{

int a,b;
printf("input 2\n");
scanf("%d%d",&a,&b);
printf("a=%d,b=%d\n",a,b);
a=a^b;
b=a^b;
a=a^b;
printf("a=%d,b=%d\n",a,b);







exit(0);
}             
