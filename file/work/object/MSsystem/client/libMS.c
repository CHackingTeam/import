#include "libMS.h"
void MSprint()
{
        printf("***************MSsystem****************\n\n");
	printf("1:search book\t\t 5:delete admin\n");
        printf("2:add    book\t\t 6:------------\n");
	printf("3:delete book\t\t 7:------------\n");
	printf("4:add admin  \t\t 8:------------\n");
        printf("9:exit MSsystem\n\n");
}
void MSsearch(int sock)
{
 	char buf[MAXLINE];
        char bufname[MAXNAME];
	printf("Enter book name:");
/*	getchar();
        gets(bufname);
		*/
	sprintf(bufname,"%s","cop");
	sprintf(buf,"MS:1%s:MS",bufname);
	write(sock,buf,strlen(buf));     /// OK:msg  or error:msg
        read(sock,buf,MAXLINE);
        if(!strcmp(buf,"NOT"))
	   printf("Empty set:%s\n",bufname);
	else
	   printf("1 row in set:%s\n",buf);   // buf->end==0,

}
void MSaddBK(int sock)
{
   char buf[MAXLINE];
   char bufname[MAXNAME];
   printf("Enter book information<'nameBK','makeBK','dateBK','updateBK'>:");
   getchar();
   gets(bufname);
   sprintf(buf,"MS:2%s:MS",bufname);
   write(sock,buf,strlen(buf));
   read(sock,buf,MAXLINE);
   if(!strcmp(buf,"NOT"))
	   printf("ERROR\n");
   else
	   printf("Query OK, 1 row affected\n");



}
void MSdeleteBK(int sock)
{
   char buf[MAXLINE];
   char bufname[MAXNAME];
   printf("Enter delete book name:");
   getchar();
   gets(bufname);
   sprintf(buf,"MS:3%s:MS",bufname);
   write(sock,buf,strlen(buf));
   read(sock,buf,MAXLINE);
   if(!strcmp(buf,"NOT"))
	   printf("Query OK, 0 rows affected\n");
   else
	   printf("Query OK, 1 row affected \n");

}
 void MSadduser(int sock)
{
   char buf[MAXLINE];
   char bufname[MAXNAME];
   printf("Enter user information<'name',age,sex,'password'>:");
   getchar();
   gets(bufname);
   sprintf(buf,"MS:4%s:MS",bufname);
   write(sock,buf,strlen(buf));
   read(sock,buf,MAXLINE);
   if(!strcmp(buf,"NOT"))
	   printf("ERROR\n");
   else
	   printf("Query OK, 1 row affected\n");



}
void MSdeleteuser(int sock)
{
   char buf[MAXLINE];
   char bufname[MAXNAME];
   printf("Enter delete user name:");
   getchar();
   gets(bufname);
   sprintf(buf,"MS:5%s:MS",bufname);
   write(sock,buf,strlen(buf));
   read(sock,buf,MAXLINE);
   if(!strcmp(buf,"NOT"))
	   printf("Query OK, 0 rows affected\n");
   else
	   printf("Query OK, 1 row affected \n");

}

