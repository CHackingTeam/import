#include <stdio.h>
#include <stdlib.h>
int cout=0;
void print(char* c,int s)
{

      c[s]=0;
      printf("%s\t--%d\n",c,cout);
}
void string_pailie(char* c,char* a,int* b,size_t size,size_t s)
{

    if(size==s){
        cout++;
        print(c,s);
       return;
    }

   for(int i=0;i<s;i++)
      if(b[i]==0){
          b[i]=1;
          c[size]=a[i];
          string_pailie(c,a,b,size+1,s);
          b[i]=0;
      }
   
   
}

int main(int argc,char** args)
{

   char a[]="HackingTeam";
   char c[sizeof(a)-1];
   int b[sizeof(a)-1];
   int size=sizeof(a)-1;
   
   for(int i=0;i<size;i++)
       b[i]=0;

   string_pailie(c,a,b,0,size);


    exit(0);
}
