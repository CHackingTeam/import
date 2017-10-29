/*************************************************************************
    > File Name: sigaction.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年05月28日 星期六 16时14分00秒
 ************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#define MAXLEN 1024*1000
typedef void (*function)(int );

function  signal_(int sig_,function f)
{
  struct sigaction sa,osa;
  sa.sa_handler=f;
  sa.sa_flags=0;
  sigemptyset(&sa.sa_mask);

  if(sig_==SIGALRM)
  {
#ifdef SA_INTERRUPT
	printf("sa_flags set SA_INTERRUPT\n");
	sa.sa_flags|=SA_INTERRUPT;
#endif
  }
  else
  {
#ifdef SA_RESTART
	  sa.sa_flags|=SA_RESTART;
#endif
 
  }

  if(sigaction(sig_,&sa,&osa)<0)
	return (SIG_ERR);
  return (osa.sa_handler);

}
void sig_handler(int sig)
{
 printf("SIGALRM\n");


}
int main(int argc,char** argv)
{
int fd;
int i=0;
char buf[MAXLEN];
int size;
signal_(SIGALRM,sig_handler);
printf("start.......\n");
if((fd=open("write.txt",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR))<0)
   perror("error file");

sprintf(buf,"hi hack!!!");
for(;i<1000;i++)
  sprintf(buf,"%shi hack!!!",buf);


//alarm(2);

if((size=write(fd,buf,strlen(buf)))!=strlen(buf)) 
         fprintf(stderr,"%s",strerror(errno));
printf("%d\n",size);
alarm(1);
while(1){
}


close(fd);


exit(0);
}


