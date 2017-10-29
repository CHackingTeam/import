#include "apue.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void sig_int(int sig)
{
    printf("sig INT\n");
}
void sig_quit(int sig)
{
    printf("sig quit\n");
}



int main(int argc,char** args)
{

if(signal(SIGINT,sig_int)==SIG_ERR)
    perror("SIGINT error");
if(signal(SIGCHLD,sig_quit)==SIG_ERR)
    perror("SIGCHLD error");

if(system("/bin/ed")<0)
    perror("system error");

    exit(0);
}
