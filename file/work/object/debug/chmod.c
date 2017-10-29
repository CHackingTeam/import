#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{

if((creat("text.c",S_IRUSR|S_IWUSR))<0)
   perror("creat error");

system("ls -l text.c");

chmod("text.c",S_IRUSR|S_IWUSR|S_IRWXG|S_IRWXO);

system("ls -l text.c");

exit(0);

}
