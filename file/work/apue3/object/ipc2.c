#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define MAXLINE 1024
int main(int argc,char** argv)
{

	int fd[2];
	char line[MAXLINE];
	int n;
    pipe(fd);
	if(fork()>0)
	{ 
		close(fd[0]);
		write(fd[1],"hi world\n",9);
    }
	else
	{
		close(fd[1]);
		n=read(fd[0],line,MAXLINE);
		write(STDOUT_FILENO,line,n);
	}




	exit(0);
}
