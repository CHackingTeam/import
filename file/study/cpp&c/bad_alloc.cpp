/*************************************************************************
    > File Name: bad_alloc.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年05月26日 星期四 22时29分23秒
 ************************************************************************/
#include <iostream>
#include <stdexcept>
using namespace std;
#define MAX 1<<64
int main()
{

	try
	{

		int* p=new int[MAX];
   	}catch(bad_alloc& c)
	{
		cout<<"bad_alloc"<<"\n"<<endl;
		c.what();
	}


	return 0;
}
