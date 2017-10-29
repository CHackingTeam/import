#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "apue.h"
#include <sys/wait.h>
int reg_lock(int fd,int cmd,int type,int whence,off_t offset,off_t len)
{

    struct flock lock;
    lock.l_type=type;
    lock.l_whence=whence;
    lock.l_start=offset;
    lock.l_len=len;

    return (fcntl(fd,cmd,&lock));
}
int main(int argc,char** args)
{
   int fd;
   pid_t pid;
   char buf[5];
   struct stat statbuf;

   if(argc!=2)
       perror("argc error ");
   if((fd=open(args[1],O_RDWR | O_CREAT |O_TRUNC,FILE_MODE))<0)
       perror("open error ");
   if(write(fd,"abdef",6)!=6)
       perror("write error");
   if(fstat(fd,&statbuf)<0)
       perror("fstat error");
   if(fchmod(fd,(statbuf.st_mode & ~S_IXGRP) | S_ISGID)<0)
       perror("fchmod error");


   reg_lock(fd,F_SETLK,F_RDLCK,SEEK_SET,0,0);

   sleep(20);



    exit(0);
}
