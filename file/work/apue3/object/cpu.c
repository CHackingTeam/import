#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <sched.h>
#include <assert.h>
#include <pthread.h>
 char b;
static pthread_barrier_t barrier_start;
static pthread_barrier_t barrier_end;
sem_t sem;
int cpu_thread1=0;
int cpu_thread2=1;
void* pthread1(void* arg)
{ 
	char c='a';
do{ 
pthread_barrier_wait(&barrier_start);
   sem_wait(&sem);
   c++;
   b=c;
   sem_post(&sem);
   pthread_barrier_wait(&barrier_end);
}while(1);
}

void* pthread2(void* arg)
{
do
 {pthread_barrier_wait(&barrier_start);
  sem_wait(&sem);
  printf("%c\n",b);
  sem_post(&sem);
   pthread_barrier_wait(&barrier_end);
 }while(1);
}

int main(int argc,char** argv)
{
assert(pthread_barrier_init(&barrier_start, NULL, 3) == 0);
    assert(pthread_barrier_init(&barrier_end, NULL, 3) == 0);
    sem_init(&sem,0,1);
	pthread_t t1;
	pthread_t t2;

	assert(pthread_create(&t2,NULL,pthread1,NULL)==0);
	assert(pthread_create(&t1,NULL,pthread2,NULL)==0);

   cpu_set_t cs;
   CPU_ZERO(&cs);
   CPU_SET(cpu_thread1,&cs);
   assert(pthread_setaffinity_np(t1,sizeof(cs),&cs)==0);
   CPU_ZERO(&cs);
   CPU_SET(cpu_thread2,&cs);
   assert(pthread_setaffinity_np(t2,sizeof(cs),&cs)==0);
   do
   {
        pthread_barrier_wait(&barrier_start);
        pthread_barrier_wait(&barrier_end);
   }while(1);
   return 0;
}
