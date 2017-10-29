#include "mm.h"
#include "memlib.h"
#define MAX (1<<12)

int main(int argc,char* argv[])
{
  mem_init(MAX);
  mm_init();
  int *p=(int*)mm_malloc(sizeof(int));
  mm_free(p);









  return 0;
}
