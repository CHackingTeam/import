#include "apue.h"
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#define BUFSIZE 500000
char buf[BUFSIZE];

void set_fl(int f,int flags)
{
    int val;
    if((val=fcntl(f,F_GETFL,0))<0)
        perror("fcntl F_GETFL error");

    val|=flags;

    if(fcntl(f,F_SETFL,val)<0)
        perror("fcntl F_SETFL error");
}

int main(int argc,char** argv)
{

    int ntowrite,nwrite;
    ntowrite=read(STDIN_FILENO,buf,BUFSIZE);
    fprintf(stderr,"read %d bytes\n",ntowrite);
 
    //sleep(3);
    set_fl(STDOUT_FILENO,O_NONBLOCK);
    
    char* ptr=buf;

    while(ntowrite>0)
    {
        errno=0;
        nwrite=write(STDOUT_FILENO,ptr,ntowrite);
        fprintf(stderr,"nwrite=%d,errno=%d\n",nwrite,errno);

        if(nwrite>0)
        {
            ptr+=nwrite;
            ntowrite-=nwrite;
        }
    }





    exit(0);
}
