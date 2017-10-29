#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
int main(int argc,char* argv[])
{
  if(argc!=2)
     perror("error argc\n");
   if(access(argv[1],R_OK)<0)
     printf("access error:%s\n",argv[1]);
  else
     printf("read access ok\n");
   if((open(argv[1],O_RDONLY))<0)
     printf("open error:%s\n",argv[1]);
   else
     printf("read open ok\n");
  






 return 0;
}
