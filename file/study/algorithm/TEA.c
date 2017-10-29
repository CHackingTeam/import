#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(unsigned int  k[],unsigned int text[]);
void decrypt(unsigned int k[],unsigned int text[]);
void test_TEA(char mode,FILE* infile,FILE* outfile,unsigned int key[]);

int main(int argc,char** argv)
{
   FILE *in=fopen(argv[1],"r+");
   FILE *out=fopen(argv[2],"r+");

   unsigned int key[]={12,23,34,45};
   char buf[]="hackingT";

   //test_TEA('b',in,out,key);
   encrypt(key,(unsigned int*)buf);
printf("%s\n",buf);
   decrypt(key,(unsigned int*)buf);
printf("%s\n",buf);


   exit(0);
}

void encrypt(unsigned int k[],unsigned int text[])
{
  unsigned int y=text[0],z=text[1];
  unsigned int delta=0x9e3779b9,sum=0;
  int n;
  for(n=0;n<32;n++)
  {
      sum+=delta;
      y+=((z<<4)+k[0])^(z+sum)^((z>>5)+k[1]);
      z+=((y<<4)+k[2])^(y+sum)^((y>>5)+k[3]);

  }
  text[0]=y;
  text[1]=z;

}

void decrypt(unsigned int k[],unsigned int text[])
{

  unsigned int y=text[0],z=text[1];
  unsigned int delta=0x9e3779b9,sum=delta<<5;
  int n;

  for(n=0;n<32;n++)
  {
     z-=((y<<4)+k[2])^(y+sum)^((y>>5)+k[3]);
     y-=((z<<4)+k[0])^(z+sum)^((z>>5)+k[1]);
   
     sum-=delta;

  }

  text[0]=y;
  text[1]=z;
}

void test_TEA(char mode,FILE* infile,FILE* outfile,unsigned int key[])
{

char buf[1024];
int i;

while(!feof(infile))
{
    i=fread(buf,1,8,infile);
    if(i<=0)
        break;
    switch(mode)
    {
      case 'e':
           encrypt(key,(unsigned int*)buf);
           break;
      case 'd':
           decrypt(key,(unsigned int*)buf);
    }
 fwrite(buf,1,8,outfile);

}
}
