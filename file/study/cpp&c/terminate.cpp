/*************************************************************************
    > File Name: terminate.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年05月22日 星期日 21时32分04秒
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <exception>
using namespace std;
void my_terminate()
{

	cout<<"hi My terminate"<<"\n"<<endl;
}
class B_
{
	public:
  B_()
  {
	  cout<<"hi B_"<<"\n"<<endl;

  }
  ~B_()
  {
     cout<<"delete B_"<<"\n"<<endl;
	  throw 47;
  }
  void print()const
  {

	  throw 3;
  }

};
void (*terminator_)()=set_terminate(my_terminate);


int main(int argc,char** argv)
{




 /* try{
  B_ b;
 b.print();
  }catch( ... )
  {
   cout<<"catch(...)"<<"\n"<<endl;


  }

*/
	
  B_ b;
	
 

	exit(0);
}
