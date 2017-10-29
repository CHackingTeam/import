#include <stdio.h>
#include <stdlib.h>
int main(int argc,char* argv[])
{
    int c=getc(stdin);
    ungetc(c,stdin);
    printf("%c\n",getc(stdin));

 



	exit(0);
}
