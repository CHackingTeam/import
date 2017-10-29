#include <stdio.h>
void print_(int c)
{
  printf("%d",c);
}
void print_number(int c)
{
   if(c>=10)
       print_number(c/10);
   print_(c%10);
}
int main(int argc,char** argv)
{
   
    print_number(102983);
    printf("\n");

    return 0;
}
