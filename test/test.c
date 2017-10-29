#include "test.h"
void init_config(struct bots_config* cnf)
{
   cJSON* root;
   int size=0;
   char buf[MAXBUF];
   FILE* fp=fopen("config","r");
   if(!fp)
	   perror("open config error");
   while(fgets(buf+size,MAXSTR,fp))
	   size+=strlen(buf+size)-1;
   root=cJSON_Parse(buf);
   cJSON* item=cJSON_GetObjectItem(root,"user");
 /*
   sprintf(cnf->user,"%s",item->valuestring);
   sprintf(cnf->cmd,"%s",item->valuestring);
   sprintf(cnf->bots,"%s",item->valuestring);
   */
   strcpy(cnf->user,item->valuestring);
   strcpy(cnf->cmd,item->valuestring);
   strcpy(cnf->bots,item->valuestring);
   cnf->pthread=item->valueint;
   fclose(fp);
}
void* pthread_main(void*)
{

	pthread_detach(pthread_self());
}

