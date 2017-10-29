#include "test.h"
	
int main(int argc,char** argv)
{
   pthread_t tid;
   init_config(&config);
   for(int i=0;i<config.pthread;i++)
     pthread_create(&tid,NULL,thread_main,NULL);



   exit(0);



}


