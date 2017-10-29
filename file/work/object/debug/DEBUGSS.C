#include <stdio.h>

int main(int argc,char* argv[])
{

char *p;
char buf[]={"freebsd hello!"};
p=buf;
char buf1[13];
char buf2[34];
//sscanf(buf,"%s",buf1);
//printf("%s\n",buf1);
for(;;)
{

printf("%d\n",*(p++));
if(*p=='\0')
  break;
}
 char c;
// scanf("%s",&c);
// printf("%d\n",c);




  return 0;
}
