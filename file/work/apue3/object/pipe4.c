#include <stdio.h>
#include <ctype.h>
int main(int argc,char** argv)
{
   int c;
   while((c=getchar())!=EOF){
	  if(isupper(c))
		  c=tolower(c);
     if(putchar(c)==EOF)
      perror("error");
     if(c=='\n')
	  fflush(stdout);
   }

	return 0;
}
