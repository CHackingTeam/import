/*************************************************************************
    > File Name: dete.h
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年06月05日 星期日 14时53分05秒
 ************************************************************************/
#ifndef DETE
#define DETE


#include <iostream>

using namespace std;

class Dete;
extern bool operator<(const Dete&,const Dete&);
extern bool operator>(const Dete&,const Dete&);
extern bool operator>=(const Dete&,const Dete&);
extern bool operator<=(const Dete&,const Dete&);
extern bool operator==(const Dete&,const Dete&);
extern bool operator!=(const Dete&,const Dete&);


class Dete
{
private:
 struct dete_
 {

	 int y;
	 int m;
	 int d;
	 dete_(int y,int m,int d):y(y),m(m),d(d){}
 };
 
struct dete_* dp;
public:

Dete();
Dete(int y,int m,int d);
Dete(const char* stringdete);

int gety()const;
int getm()const;
int getd()const;


~Dete();



friend bool operator<(const Dete&,const Dete&);
friend bool operator>(const Dete&,const Dete&);
friend bool operator>=(const Dete&,const Dete&);
friend bool operator<=(const Dete&,const Dete&);
friend bool operator==(const Dete&,const Dete&);
friend bool operator!=(const Dete&,const Dete&);





};
#endif 


