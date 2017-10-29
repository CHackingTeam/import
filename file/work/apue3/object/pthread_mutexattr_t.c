#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
pthread_mutexattr_t b;
int main(int argc,char** argv)
{

int c;
int err;
pthread_mutexattr_init(&b);
 
err=pthread_mutexattr_getpshared(&b,&c);
if(err)
    exit(err);
if(c==PTHREAD_PROCESS_SHARED)
    printf("PTHREAD_PROCESS_SHARED\n");
else
    printf("no PTHREAD_PROCESSS_SHARED\n");

pthread_mutexattr_destroy(&b);






    exit(0);
}
