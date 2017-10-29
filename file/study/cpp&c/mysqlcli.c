#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

#define MYSQL_USE "mysql"
#define MYSQL_TABLE "student"
#define MYSQL_PASSWORD "root"
#define MYSQL_USER "root"
#define MYSQL_ADDER "localhost"


const char* sql[]={"SELECT * from student","insert into student vaules(5,"gcc",90,NULL)"};

int main(int argc,char** argv)
{
   int i=0;
   MYSQL* conn;
   MYSQL_RES* result;
   MYSQL_ROW row;
   conn=mysql_init(NULL);
   if(mysql_real_connect(conn,MYSQL_ADDER,MYSQL_USER,MYSQL_PASSWORD,MYSQL_USE,0,NULL,0)==NULL){
       fprintf(stderr,"sorry,no database connect ...\n");
       return exit(1);
   }

   if(mysql_query(conn,sql[0])){
       fprintf(stderr,"%s\n",mysql_error(conn));
       fprintf(stderr,"%s\n",sql);
       return exit(1);
   }






    exit(0);
}
