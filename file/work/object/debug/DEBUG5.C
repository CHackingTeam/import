#include <stdio.h>
#define MAXLEN 30
#define INDEX 10000
int debug(int index)
{
  int i=0;
  char a[MAXLEN];
  for(;i<MAXLEN+index;i++)
    a[i]='a';
return 0;
}
int main(int argc,char* argv[])
{
 /* 
 FILE* fp;
 int i;
 if((fp=fopen("file.txt","r+"))==NULL)
    printf("error open file.txt\n");
 for(i=0;i<INDEX;i++)
    fprintf(fp,"%d\n",i);
 
*/
int i;



for(i=0;i<INDEX;i++)
{
 printf("%d\n",i);
 debug(i);
 
}
  printf("next -> one\n");
  printf("next -> two\n");

return 0;
}
