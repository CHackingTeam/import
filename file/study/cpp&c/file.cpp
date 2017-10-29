#include <iostream>
#include <fstream>

using namespace std;

int main()
{

string line;

ifstream in("out");

while(getline(in,line))
	cout<<line<<"\n"<<endl;


	return 0;
}
