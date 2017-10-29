#include <stdio.h>
struct sa
{
int c;
float b;
};
int main(int argc,char* argv[])
{
  struct sa c;
  c.c=0;
  c.b=0.1;

  FILE* p=fopen("text.txt","w+");
  fwrite(&c,sizeof(struct sa),1,p);





	return 0;
}
