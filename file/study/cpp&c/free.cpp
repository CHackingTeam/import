#include <iostream>
#include <cstdio>
#include <csetjmp>
using namespace std;

jmp_buf c;


class fr
{
	public:
		fr()
		{
			cout<<"fr()"<<"\n"<<endl;

		}
		~fr()
		{

			cout<<"~fr()"<<"\n"<<endl;
		}

};

int main()
{

	if(setjmp(c)==0){

		fr a;
		longjmp(c,1);
	}

return 0;
}
