/*************************************************************************
    > File Name: unexpected.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年05月28日 星期六 20时59分50秒
 ************************************************************************/
#include <iostream>
#include <stdexcept>
#include <exception>
#include <cstdio>
using namespace std;
class b{

};
class c{

};
void my_terminal(void)
{
  printf("start throw my_terminal\n");
}
void throw_function(void)throw(c,b)
{

	printf("start throw ...\n ");

	throw 34;

}
void my_unexpected(void)
{

printf("start throw unexpected......\n");
}
void t(){

	throw c();
}
void f()throw(b,bad_exception)
{

	t();
//	throw_function();

}
int main(int argc,char** argv)
{

set_terminate(my_terminal);
set_unexpected(my_unexpected);




try{

  f();
	}catch(bad_exception&)
{

	printf("throw...\n");
}


	return 0;
}
