#include <iostream>
#include <cstdio>
using namespace std;
#define SUM(x) cout<<#x "="<<x<<endl
#define FIELD(a) char* a##_string; int a##_int
int main()
{
int c=9;
SUM(c);
FIELD(one);



	return 0;
}
