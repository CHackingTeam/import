/*************************************************************************
    > File Name: auto_ptr_class.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年05月26日 星期四 20时40分25秒
 a************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;
template <class T>
class auto_ptr
{
private:
  T* date;
public:
  auto_ptr(T* da)
  {
	  cout<<"auto_ptr()"<<"\n"<<endl;
	  date=da;
  }
 T&  operator*()
 {
	 return *date;
 }
T* operator->()const
{
	return date;
} 
~auto_ptr()
{

	delete date;

}

};

class c
{
private:
		int i;
public:
		c()
		{
			cout<<"c(new)"<<"\n"<<endl;
		}
	c(int c=0):i(c)
	{
		cout<<"c()"<<"\n"<<endl;

	}
  void print()const
 {
  cout<<"i="<<i<<"\n"<<endl;

 } 
    ~c()
	{
		cout<<"delete c"<<"\n"<<endl;

	}


};
void f()
{
	auto_ptr<c> auto_(new c(4));
	auto_->print();
	cout<<"f()"<<"\n"<<endl;
	(*auto_).print();
	cout<<"f()"<<"\n"<<endl;


}
int main(int argc,char** argv)
{
	cout<<"start"<<"\n"<<endl;

   f();


cout<<"end"<<"\n"<<endl;
	exit(0);
}


