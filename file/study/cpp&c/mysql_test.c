#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define HOST "localhost"
#define USERNAME "root"
#define PASSWORD "931210"
#define DATABASE "mysql"
int main(void)
{

    MYSQL mysql;
    MYSQL_ROW row;
    MYSQL_RES *result;
    unsigned int num_fields;
    unsigned int i;
    pid_t c;   
    mysql_init(&mysql);
   
    if(!mysql_real_connect(&mysql, HOST, USERNAME, PASSWORD, DATABASE, 0, NULL, 0))
       printf("Connection failed,%s\n",mysql_error(&mysql));
    mysql_query(&mysql, "set names utf8");
    
  if((c=fork())==0)
{
   unsigned int num_fields_;
    MYSQL_ROW row_;
    MYSQL_RES *result_;
do{
printf("child\n");
   if(!mysql_query(&mysql,"SELECT * FROM Mbook")){
        result_= mysql_store_result(&mysql);
        if(!result_){
           perror("result error.");
           exit(1);
        }   

        num_fields_ = mysql_num_fields(result_);

        while(row_= mysql_fetch_row(result_))
        {

            for(i=0; i<num_fields_; i++)
                printf("%s\t",row_[i]);

            printf("\n");
        }
}

        
   }while(1);
mysql_free_result(result_);
}

else
{
  do{
     printf("parent\n");

     if(!mysql_query(&mysql,"SELECT * FROM MSbook")){
        result = mysql_store_result(&mysql);
        if(!result){
           perror("result error.");
           exit(1);
        }   

        num_fields = mysql_num_fields(result);

        while(row = mysql_fetch_row(result))
        {

            for(i=0; i<num_fields; i++)
                printf("%s\t",row[i]);

            printf("\n");
        }
   }
}while(1);

        mysql_free_result(result);
}
    mysql_close(&mysql);

    return 0;

}
