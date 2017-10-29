#include <pthread.h>
#include <stdio.h>
#include <assert.h>
pthread_t pt1;
pthread_t pt2;
int ok=0;
int x=0;
void do_(int x)
{
    printf("x=%d\n",x);
}
void* pth1()
{
    while(!ok)
        do_(x);
}

void* pth2()
{
    x=42;
    ok=1;
}


int main(int argc,char** argv)
{
 assert(pthread_create(&pt1,NULL,pth1,NULL)==0);
 assert(pthread_create(&pt2,NULL,pth2,NULL)==0);
 
 pthread_join(pt1,NULL);
 pthread_join(pt2,NULL);



    return 0;
}
