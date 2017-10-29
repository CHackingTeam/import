#include <iostream>
#include <cstdio>
using namespace std;


class overflow{
 private:
	 int a;
	 int c;
 public:
     overflow(int n=1,int m=0)
	 {
		 a=n;
		 c=m;
	 }
	 ~overflow()
	 {
       cout<<"~overflow"<<"\n"<<endl;

	 }
	 void print()
	 {
		 cout<<"a="<<a<<"\t"<<"c="<<c<<"\n"<<endl;
	 }


};


int main()
{
  overflow* p=new overflow(3,4);
  p->print();
  int * c=(int*)p;
  printf("%d\n",*c);
  c++;
  printf("%d\n",*c);


	return 0;

}
