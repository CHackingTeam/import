#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char** argv)
{
   FILE* out_;
   FILE* in_;

   char buf[1024];
   if((out_=popen("./out","r"))==NULL)
	   perror("error out");
   if((in_=popen("./in","w"))==NULL)
	   perror("error in");

   while(fgets(buf,1024,out_)!=NULL)
	   if(fputs(buf,in_)==EOF)
		   perror("error in");

   pclose(out_);
   pclose(in_);
	    

	exit(0);
}
