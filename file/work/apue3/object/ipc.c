#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char** argv)
{
   int fd[2];
   pipe(fd);
   close(fd[0]);
   if(write(fd[1],"hi pipe",strlen("hi pipe"))==-1)
	   perror("write error");




	exit(0);
}
