#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(int argc,char** argv)
{

  char* path="/usr/bin/less";
  char* name="less";
  int fd[2];
  FILE* fdp;
  pid_t pid;
  char buf[1024];
  int n;

  if(argc!=2)
	  perror("usage: a.out <pathname>");
  if((fdp=fopen(argv[1],"r"))==NULL)
    perror("open file test.cs error");
  pipe(fd);

  if((pid=fork())>0)
  {
   close(fd[0]);
   while(fgets(buf,1024,fdp)!=NULL){
     n=strlen(buf);
     write(fd[1],buf,n);

   }
   close(fd[1]);
   waitpid(pid,NULL,0);
  }
  else
  {
    close(fd[1]);
	dup2(fd[0],STDIN_FILENO);
	if(execl(path,name,(char*)0)<0)
		perror("error execl less");
  }


	exit(0);

}

