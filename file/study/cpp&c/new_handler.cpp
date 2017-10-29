#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int i=1;
void reqiure(void)
{
  printf("error new:%d\n",i);
//  fflush(stdout);
  exit(1);

}

int main(int argc,char* argv[])
{ 
  int *p;
  set_new_handler(reqiure);
  while(i)
  {
    p=new int[1000];
    if(p==NULL)
      break;
   i++;
  }




  return 0;
}
