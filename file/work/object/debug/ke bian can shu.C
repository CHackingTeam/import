#include <stdio.h>
#include <stdarg.h>
int vpf(char *fmt, ...)
{

int count;
count=sizeof(fmt);
printf("%d\n",count);
  va_list argptr;
  int cnt;
  va_start(argptr,fmt);
printf("%d\n",count);
  cnt=vprintf(fmt,argptr);
  va_end(argptr);


  return cnt;
}

int main(int argc,char* argv[])
{

  int i=9;

  vpf("%d\n",i);


  return 0;
}
