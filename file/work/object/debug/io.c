#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc,char* argv[])
{
         size_t n;
         char buf[]={"hello world"};
	 char bufr[56];
	 FILE* p;
/*	 if(argc!=2)
		 printf("error \n");*/
	 if((p=fopen("text.txt","w+"))==NULL)
		 printf("error open text.txt\n");
         n=fwrite(buf,11,1,p);
      //   fflush(p);
          //fseek(p,0,SEEK_SET);
    	// fread(bufr,11,1,p); 
 //n=fwrite(buf,11,1,p);
 
	
	for(n=0;n<11;n++)
           printf("%c\t",bufr[n]);
         printf("write n=%d\n",n);
 
	 fclose(p);
           
	return 0;
}
