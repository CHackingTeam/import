#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <unistd.h>
using namespace std;
/*
void print()
{
	int i;
 for(i=0;i<1000;i++)
 {
   cout<<"/"<<endl;
   cout<<"|"<<endl;
   cout<<"\\"<<endl;
   


 }
 cout<<"\n"<<endl;


}*/
int main(void)
{
    ifstream in("code.c");
    
    string line;
     int i=1;
    while(getline(in,line))
    {      
	  // i/=2;
          sleep(i);
          cout<<"\\>\t"<<line<<"\n"<<endl;;
	  //print();
      }




	return 0;
}
