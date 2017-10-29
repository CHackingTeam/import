/*************************************************************************
    > File Name: ha.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年05月31日 星期二 11时15分17秒
 ************************************************************************/#include <stdio.h>
void mov(char to,char from)
{

  printf("%c->%c\n",to,from);

}

void hanno(char a,char b,char c,int n)
{
 if(n==1)
   mov(a,c);
 else
 {
   hanno(a,c,b,n-1);
   mov(a,c);
   hanno(b,a,c,n-1);
}
}





int main(int argc,char* argv)
{

if(argc!=2)
  printf("error\n");

hanno('A','B','C',argv[1]);



	return 0;
}

