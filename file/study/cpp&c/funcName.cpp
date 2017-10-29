#include <iostream>
#include <cstdio>

using namespace std;

extern "C"
{
int f(int x)
{

	return x;
}
}
int f(int x,int b)
{

	return x+b;

}

int main()
{

   printf("%d\n",f(5));
   printf("%d\n",f(5,7));




	return 0;
}
