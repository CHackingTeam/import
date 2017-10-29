#include <stdio.h>
#include <stdlib.h>

#define MAX_CODE_LINE     1024
#define MAX_CODE_SIZE     100
#define MAX_INCLUDE_LINE  100
#define MAX_DEFINE_LINE   100<<2
 



char* buf[MAX_CODE_LINE];
char* include_line[MAX_INCLUDE_LINE];
char* define_line[MAX_DEFINE_LINE];
char* main_code_start   = "int main(int argc,char** argv)\n{";
char* main_code_end     = "exit(0)\n}";

void mymalloc(char* str,char* buff,int size)
{

  




}
void buile_code(char* str)
{
   static int include_cout=0;
   static int define_cout=0;
   static int buf_cout=0;

   char* p=str;
   if(*p=='#')
       if(*(p+1)=='i')
           mymalloc(str,include_line,include_cout),include_cout++;
       else
           mymalloc(str,define_line,define_cout++),define_cout++;
   else
      mymalloc(str,buf,buf_cout),buf_cout++;

}


int main(int argc,char** argv)
{

    FILE* fp;
    if(argc!=2){
        perror("input express");
        exit(0);
    }
    if((fp=fopen("code.c","+r"))==NULL)
        perror("open code.c error");
     






    exit(0);
}
