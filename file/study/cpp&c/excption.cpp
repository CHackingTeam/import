/*************************************************************************
    > File Name: excption.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年05月26日 星期四 21时54分15秒
 ************************************************************************/
#include <iostream>
//#include <exception>
#include <stdexcept>

using namespace std;

class error_me : public runtime_error
{

	public:
		error_me(const string& msg=""):runtime_error(msg){
		
		}


};



int main(int argc,char** argv)
{
try{

	cout<<"try"<<"\n"<<endl;
    throw error_me("hi error_");
}
catch(error_me& c)
{
	cout<<"catch(error_& c)"<<"\n"<<endl;
    c.what();



}

cout<<"hi start"<<"\n"<<endl;


	return 0;
}
