#include "shell.h"

void eval(char* cmdline)
{
  char* argv[MAXARGS];
  char buf[MAXLINE];
  int bg;
  pid_t pid;

  strcpy(buf,cmdline);
  bg=parseline(buf,argv);

  if(argv[0]==NULL)
    return;
  if(!builtin_command(argv)) {
    if((pid=fork())==0)
    {
      if(execve(argv[0],argv,0)<0)
      {
        printf("%s:command not found!\n",argv[0]);
        exit(0);
      }
    }
  

 if(!bg)
 {
   int status;
   if(waitpid(pid,&status,0)<0)
     perror("waitfg:pid error\n");
 }
 else
   printf("%d %s",pid,cmdline);

  }

 return;
}


