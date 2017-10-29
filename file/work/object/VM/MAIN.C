#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_I 100000000
extern void mem_init(void);
extern int mm_init(void);
extern void* mm_malloc(size_t size);
extern void mm_free(void* p);
int main(int argc,char* argv[])
{
 mem_init();
 mm_init();
 /*
 clock_t start=clock();
 clock_t end;
 int i;
 int *p;
 for(i=0;i<MAX_I;i++)
    {
    p=(int*)mm_malloc(sizeof(int));
    mm_free(p);

    }
 end=clock();
 printf("mm_malloc time:\t%ld\n",(end-start)/CLOCKS_PER_SEC);
 end=clock();
for(i=0;i<MAX_I;i++)
{
  p=(int*)malloc(sizeof(int));
  free(p);
}
start=clock();
printf("malloc time:\t%ld\n",(start-end)/CLOCKS_PER_SEC);


*/





  int* p;
 p=(int*)mm_malloc(sizeof(int));
 *p=3;
 char* p2=(char*)mm_malloc(sizeof(char));
 *p2='v';
 printf("nu:%d\taddr:%d\n",*p,p);
 printf("char:%c\taddr:%d\n",*p2,p2);
 mm_free(p2);
 mm_free(p);
 p=(int*)mm_malloc(sizeof(int));
 *p=3;
 p2=(char*)mm_malloc(sizeof(char));
 *p2='v';
 printf("nu:%d\taddr:%d\n",*p,p);
 printf("char:%c\taddr:%d\n",*p2,p2);
 mm_free(p);
 mm_free(p);

 return 0;
}
