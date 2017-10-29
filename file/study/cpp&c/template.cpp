#include <iostream>
using namespace std;
template <class T>
class arry
{
private:
   enum {size=100};		
   T a[size];
 public:
   T& operator[](int index)
   {
      if(index<0||index>=size)
	  cout<<"error  index "<<"\n"<<endl;

      return a[index];
   }
};
int main(int argc, char* agrv[])
{
  arry<int> c;
  arry<float> f;
  int index;
  for(index=0;index<10;index++)
     c[index]=index;
  for(index=0;index<10;index++)
      cout<<c[index]<<"\n"<<endl;
  f[0]=1.2;
  cout<<f[0]<<"\n"<<endl;

  return 0;
} 
