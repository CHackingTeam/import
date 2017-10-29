#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


int main()
{

	ifstream in("list.cpp");
    string c;
	vector<string>::iterator it;
	vector<string> str;
	

	while(getline(in,c))
      str.push_back(c);
	for(it=str.begin();it!=str.end();it++)
		cout<<*it<<endl;

          




	return 0;
}

