#include <iostream>
#include <cstdio>
using namespace std;

class ainline
{
  private:
	  int a;
  public:
	  ainline(int c=0)
	  {
        a=c;
	  }
	  inline int  print(int x)
	  {

		cout<<"a+x"<<a+x<<"\n"<<endl;
	  }
   ~ainline()
   {
	   cout<<"~a()"<<endl;
   }
};
int main()
{

ainline c(5);
c.print(6);



	return 0;
}
