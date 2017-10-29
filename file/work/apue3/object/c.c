#include <stdio.h>
#include <stdlib.h>
 extern char** environ;

int main(int argc,char** argv)
{

   char** p=environ;
   char* agger=NULL;
   while(*p!=NULL){
	   printf("%s\n",*p);
       p++;
   }

if((agger=getenv("HOME"))==NULL)
   printf("no PAGER exe\n");
else
	printf("%s\n",agger);


	exit(0);
}
