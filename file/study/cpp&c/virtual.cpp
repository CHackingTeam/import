#include <iostream>
#include <string>
using namespace std;
class ini
{

	private:
		int id;
                string name;
        public:
		ini(int id,string name):id(id),name(name)
	        {
		cout<<"ini(int,string)"<<"\n"<<endl;
	        }
		ini(const ini& a)
		{
                   id=a.id;
		   name=a.name;
		}

		virtual void print(void)
		{
			cout<<"ini id=\t"<<id<<"\n"<<endl;
			cout<<"ini name=\t"<<name<<"\n"<<endl;
		}
                virtual void print_(void)
{
cout<<"ini id=\t"<<id<<"\n"<<endl;



}
		~ini()
		{
			cout<<"delete\t"<<name<<"\n"<<endl;
		}
};
class ini_:public ini
{
            private:
		  string name;
	    public:
		  ini_(string name,int c):ini(c,name+"ini"),name(name){
		  cout<<"call ini_(string)"<<"\n"<<endl;

		  }
		  ini_(const ini_& a):ini(255,a.name+"ini")
	          {
                  name=a.name;
                   }
      void print_()
{cout<<"ini_ name=\t"<<name<<"\n"<<endl;}
		  void print()
		  {
                  cout<<"ini_ name=\t"<<name<<"\n"<<endl;

		  }
		  
};

void tune(ini& c)
{
c.print();

}
int main(void)
{
  /*
 ini_ c("hello centos",1234);
 ini cw(4321,"hello cetos");
 tune(c);
 tune(cw);
*/  
cout<<"szie=\t"<<sizeof(ini)<<"\n"<<endl;







	return 0;
}
