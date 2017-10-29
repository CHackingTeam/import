#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
int fp;
  if((fp=open("file.txt",O_RDWR))==-1)
       perror("error no scha file\n");
 if(fork()==0)
 {
    for(;;)
      printf("hello FreeBSD\n");

   

 }

dup2(fp,STDOUT_FILENO);
wait(NULL);




  return 0;
}
