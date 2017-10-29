#include <stdio.h>
#include <stdlib.h>

#define CHAR_MAX 255

char* assert_char(char* str,int* a)
{   
    char* s=str+9;
    char* p=str;
    char* p2;
    while(*p!=0)
    {
        a[*p]++,p++;
        if(a[*p]==1&&s>p)
            s=p;
        else{
            p2=str;
            while(p2!=p){
                p2++;
                if(a[*p2]==1)
                  {
                    s=p2;
                    break;
                  }
            }
            }
    }

    return s;
        
}

int main(int argc,char**argv)
{
  int a[CHAR_MAX];
  char* s="abaccdeff";
  for(int i=0;i<CHAR_MAX;i++)
      a[i]=0;
  printf("%c\n",*assert_char(s,a));
  
  
  /*
  for(int i=0;i<CHAR_MAX;i++)
      if(a[i]==1)
      { 
          p=s;
          while(*p!=i) p++;
          if(p<pos_min)
              pos_min=p;
      }
  printf("%c\n",*pos_min);
  */
    exit(0);
}
