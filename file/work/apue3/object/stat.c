#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#define N 3
int main(int argc,char* argv[])
{
   struct stat buf;
   char* ptr;
   int i=1;
   
 for(;i<4;i++)
{
   printf("%s:",argv[i]);
   if(lstat(argv[i],&buf)<0)
   {
      perror("error file");
     continue;
   }
   
   if(S_ISREG(buf.st_mode))
      printf("REG\n");
   else if(S_ISDIR(buf.st_mode))
     printf("DIR\n");
   else if(S_ISSOCK(buf.st_mode))
     printf("SOCKET\n");

    else
      printf("** nuknown mode **\n");
}

exit(0);

}
