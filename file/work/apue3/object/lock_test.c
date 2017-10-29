#include <stdio.h>
#include <stdlib.h>
#include "apue.h"
#include <fcntl.h>
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
int test_lock(int fd,int type,int whence,off_t offset,off_t len)
{

    struct flock f_lock;
    f_lock.l_type=type;
    f_lock.l_start=offset;
    f_lock.l_whence=whence;
    f_lock.l_len=len;

    if(fcntl(fd,F_GETLK,&f_lock)<0)
            perror("fcntl error args=F_GETLK");
    if(f_lock.l_type==F_UNLCK)
            return 0;

    return (f_lock.l_pid);
}

int main(int argc,char** args)
{


int fd;
int b;
pid_t pid;
if((fd=open("tmp.txt",O_RDWR))==-1)
   perror("error open() args=tmp.txt&&O_RDWR");

//reg_lock(fd,F_SETLK,F_WRLCK,SEEK_SET,0,0);

// if(write(fd,"dfg",3)!=3)
  //    perror("error write");
 
if(test_lock(fd,F_WRLCK,SEEK_SET,0,0)!=0)
  perror("error lock");


/*

if((b=test_lock(fd,F_WRLCK,0,SEEK_SET,5))==0)
   printf("lock file YES\n");
else
  printf("lock file NO pid=%d\n",b);

printf("pid=%d\n",getpid());

reg_lock(fd,F_SETLK,F_WRLCK,SEEK_SET,0,0);

if((pid=fork())==0)
{
int c;
  if((c=test_lock(fd,F_WRLCK,0,SEEK_SET,5))==0)
   printf("lock file YES\n");
  else
  printf("lock file NO pid=%d\n",c);
  exit(0);
}
*/

//wait(NULL);
   exit(0);
}


