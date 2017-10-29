/*************************************************************************
    > File Name: main.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年06月05日 星期日 15时32分04秒
 ************************************************************************/
#include <iostream>
#include "dete.h"
                                                       //1996 02 04
#define SUM(X)  (X.gety()*10000+X.getm()*100+X.getd())

using namespace std;

bool operator<(const Dete& x1,const Dete& x2)
{
  int x1_=SUM(x1);
  int x2_=SUM(x2);
  if(x1_<x2_)
	return 1;
   else
	 return 0;

}

bool operator>(const Dete& x1,const Dete& x2)
{
   int x1_=SUM(x1);
   int x2_=SUM(x2);
   if(x1_>x2_)
	  return 1;
   else
	 return 0;

}

bool operator<=(const Dete& x1,const Dete& x2)
{
   int x1_=SUM(x1);
   int x2_=SUM(x2);

   if(x1_<=x2_)
	 return 1;
   else 
	 return 0;
}
bool operator>=(const Dete& x1,const Dete& x2)
{
    
	int x1_=SUM(x1);
	int x2_=SUM(x2);
	if(x1_>=x2_)
	  return 1;
	else
	return 0;
}
bool operator==(const Dete& x1,const Dete& x2)
{
    int x1_=SUM(x1);
	int x2_=SUM(x2);
	if(x1_==x2_)
	  return 1;
	else 
	  return 0;
}
bool operator!=(const Dete& x1,const Dete& x2)
{
    int x1_=SUM(x1);
	int x2_=SUM(x2);
	if(x1_!=x2_)
	  return 1;
	else
	  return 0;

}

int main(int argc,char** argv)
{

Dete d("19960204");
Dete d2("19980204");
Dete d3("19960404");
Dete d4("19960205");


cout<<"y:"<<d.gety()<<"\n"<<endl;
cout<<"m:"<<d.getm()<<"\n"<<endl;
cout<<"d:"<<d.getd()<<"\n"<<endl;

if(d<d2)
   cout<<"d<d2\n"<<endl;
if(d3<d4)
    cout<<"d3>d4\n"<<endl;
cout<<"d3:"<<SUM(d3)<<"\n"<<endl;
cout<<"d4:"<<SUM(d4)<<"\n"<<endl;





	return 0;
}



