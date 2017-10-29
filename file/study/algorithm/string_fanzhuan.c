#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF 1024

char* string_f(char* str,char* top)
{
  char a[MAX_BUF];
  char* top2=top+1;
  char* top3=top;
  int i=0;
  while(*top2!=' '&&*top2!=0)
      top2++;
  while(++top!=top2)
      a[i++]=*top;
      a[i]=' ';

  top--;
while(--top3!=str)
   *top=*top3,top--;
*top=*top3;

for(int c=0;c<=i;c++)
    str[c]=a[c];
   
 
return top2-1;
}



void string_fan(char* str,size_t size)
{
   char *top=str;
    while(*(top++)!=0)
       if(*top==' ')
           top=string_f(str,top);
}
int main(int argc,char** argv)
{

    char str[]="I hacking and i am  sdf dsf ds f dsf  ds f ds f ds  f ds f ds f  ds f ds  f ew f  sd f e  f s  df  es f  e s f  es f  sstudent";

    string_fan(str,sizeof(str)-1);

   printf("%s\n",str);

    exit(0);
}
