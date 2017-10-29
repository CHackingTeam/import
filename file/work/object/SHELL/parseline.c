#include "shell.h"

int parseline(char* cmdline,char** argv)
{
 int argc=0;
 char* delim;
 int bg;
 int i=0;
 //for(;i<=strlen(cmdline);i++)
   // printf("cmd:%d\n",cmdline[i]);
 cmdline[strlen(cmdline)-1]=' ';

 while(*cmdline&&(*cmdline==' '))
    cmdline++;
 
while((delim=strchr(cmdline,' '))){

  argv[argc++]=cmdline;
  *delim='\0';
  cmdline=delim+1;

  while(*cmdline&&(*cmdline==' '))
     cmdline++;
}
argv[argc]=NULL;
//int i=0;
//for(;i<argc;i++)
 //printf("command:%s\n",argv[i]);


if(argc==0)
  return 1;


if((bg=(*argv[argc-1]=='&'))!=0)
    argv[--argc]=NULL;

return bg;

}
