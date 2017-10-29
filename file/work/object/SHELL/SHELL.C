#include "shell.h"



int main(int argc,char* argv[])
{

 char cmdline[MAXLINE];
 
 while(1)
 {
   printf("unix./>");
   fgets(cmdline,MAXLINE,stdin);
  
   if(feof(stdin))
     exit(0);
  

   eval(cmdline);

 }

   return 0;
}


