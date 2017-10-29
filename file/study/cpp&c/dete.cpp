/*************************************************************************
    > File Name: dete.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年06月05日 星期日 15时08分06秒
 ************************************************************************/
#include "dete.h"
#include <cstdlib>
Dete::Dete(){
}

Dete::Dete(int y,int m,int d)
{
     
	dp=new dete_(y,m,d);
}
Dete::Dete(const char* stringdete)
{
  // 19960901
	int ymd=atoi(stringdete);
    dp=new dete_(ymd/10000,(ymd%10000-ymd%100)/100,ymd%100);
}

Dete::~Dete()
{
	delete dp;
}

int Dete::gety()const{

	return dp->y;
}
int Dete::getm()const{

	return dp->m;
}
int Dete::getd()const{

	return dp->d;
}



