#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MRMW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main(int argc,char* argv[])
{

  umask(0);
  if((creat("text.txt",MRMW))<0)
    perror("error creat\n");
   umask(S_IRUSR|S_IWUSR);
  if((creat("text2.txt",MRMW))<0);
    perror("error creat\n");


exit(0);
}
