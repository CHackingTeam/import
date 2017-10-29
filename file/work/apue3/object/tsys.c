#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc,char** argv)
{
  if(argc!=2)
      perror("error argc");

  printf("uid=%d euid=%d\n",getuid(),geteuid());
  system(argv[1]);


    exit(0);
}

