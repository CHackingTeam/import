#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 1024

void KMP_Abate(const char* key,char* Abate,size_t size)
{
   int t=0;
   Abate[0]=0;

   for(int s=1;s<size;s++){
       while(t>0&&key[s+1]!=key[t+1]) t=Abate[t];
       if(key[s+1]==key[t+1])
       {
           t+=1;
           Abate[s+1]=t;
       }
       else
           Abate[s+1]=0;
   }
}

char* KMP(const char* str,const char* key,const char* Abate,size_t size_str,size_t size_key)
{

    int s=0;
    for(int t=1;t<size_str;t++){
        while(s>0&&str[t]!=key[s+1]) s=Abate[s];
        if(str[t]==key[s+1]) s=s+1;
        if(s==size_key) return "yes";
    }
  
    return "no";
}
int size_string(char* s)
{
    int c=0;
    while(*s!=0)
        c++,s++;
 return c;
}

int main(int argc,char** argv)
{

   if(argc!=3)
       perror("agrc error");

   char *keyworld=argv[1];
   char *str     = argv[2];
   size_t size_key=size_string(argv[1])-1;
   size_t size_str=size_string(argv[2]);
   char Abate_fun[MAX_LINE];
   printf("%d,%d\n",size_key,size_str);

   KMP_Abate(keyworld,Abate_fun,size_key);

   printf("%s\n",KMP(str,keyworld,Abate_fun,size_str,size_key));
    exit(0);
}
