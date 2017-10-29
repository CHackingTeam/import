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

		 void print(void)
		{
			cout<<"ini id=\t"<<id<<"\n"<<endl;
			cout<<"ini name=\t"<<name<<"\n"<<endl;
		}
		~ini()
		{
			cout<<"delete\t"<<name<<"\n"<<endl;
		}
};
int main(void)
{
  cout<<"szie=\t"<<sizeof(ini)<<"\n"<<endl;

   


  return 0;


}
