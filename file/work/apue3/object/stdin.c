#include <stdio.h>
#include <string.h>

int main(int argc,char** argv)
{
   char buf[1024];
   gets(buf);
   printf("in=%s\n",buf);



	return 0;
}
