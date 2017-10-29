#include <stdio.h>
#include <assert.h>
int mycopy(char* src,char* dec,size_t size)
{
  assert(src!=NULL&&src!=NULL);
 
  if(src<dec&&dec<src+size)
      for(int i=size-1;i>=0;i--)
          dec[i]=src[i];

  else
      for(int i=0;i<size;i++)
          dec[i]=src[i];

  return 0;

}
int main(int argc,char** args)
{

   char a[]="abcdefg";
   mycopy(a,a+3,4);
   printf("%s\n",a);


               



    return 0;
}    
