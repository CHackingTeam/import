/*************************************************************************
    > File Name: main.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年04月14日 星期四 16时56分06秒
 ************************************************************************/
#include <iostream>
#include <cstdio>
//#incldue <string.h>
#include "plist.h"
#include "plist.cpp"
using namespace std;

int main(int argc,char* argv[])
{
   list<int>  l;
   int i;

   for(i=0;i<10;i++)
      l.add(new int(i));
   list<int>::iterator iti(l);
   iti++;
   cout<<"it++\t"<<*(*iti)<<"\n"<<endl;
   cout<<"l[1]\t"<<*l[1]<<"\n"<<endl;
   cout<<"***********************\n"<<endl;
   cout<<"\tstring\n"<<endl;
   cout<<"***********************\n"<<endl;
   list<string> str;
   char p[]="string 0";
   for(i=0;i<10;i++)
   {

     p[7]=48+i;
	 printf("%s\n",p);
     str.add(new string(p));

   }
   list<string>::iterator its(str);
   its++;
   cout<<"str[0]\t"<<*str[0]<<"\n"<<endl;
   cout<<"its++\t"<<*(*its)<<"\n"<<endl;

    
   return 0;
}

