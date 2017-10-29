#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char** argv)
{
  FILE* in_;
  char buf[1024];

  if((in_=popen("./out","r"))==NULL)
	  perror("error");

  while(1)
  {
       fputs("input>",stdout);
	   fflush(stdout);
	   if(fgets(buf,1024,in_)==NULL)
		   break;
	   if(fputs(buf,stdout)==EOF)
		   perror("error");
  }


  pclose(in_);

  putchar('\n');
	exit(0);
}
