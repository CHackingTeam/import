#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc,char* argv[])
{
  int fp;
  char a[521]="hello freebsd";
  char b[20];
  char c[20];
  char* d=b;
  char* f=c;
  int i;   
 for(i=0;i<20;i++)
 
    b[i]=11;
     // sscanf(a,"%s %s %s",&b,&c);
  sscanf(a,"%s%s",b,c);                    // %s",b,c);                  //&b,&c);
  printf("%s,%s\n",b,c);
for(i=0;i<20;i++){
    printf("%d\t%d\n",*d,*f);
    f++,d++;
}                                     //  int fp;
  printf("input >>>>>>\n");
  if((fp=open("file.txt",O_WRONLY))==-1)
      perror("error no such file!\n");
                                         // strerr//`
  printf("start stdio->file.txt\n");

 dup2(fp,STDOUT_FILENO);//ON);

printf("kan dao le\n");

exit(0);
}



