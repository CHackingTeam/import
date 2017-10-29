#include <iostream>
#include <cstdlib>

using namespace std;

void* operator new(size_t size)
{
   cout<<">>>>opeartor new\n"<<endl;

   void* p=malloc(size);
   return p;



}

void operator delete(void* ptr)
{
  cout<<">>>>operator delete\n"<<endl;

  free(ptr);
}

int main(int argc,char* argv[])
{


  int* p=new int(0);
  cout<<*p<<"\n"<<endl;

  delete p;




  exit(0);
}
