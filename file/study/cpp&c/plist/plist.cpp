/*************************************************************************
    > File Name: plist.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年04月13日 星期三 22时59分48秒
 ************************************************************************/
#include "plist.h"
#include <cassert>
#include <cstring>

template <class T,int c>
T* list<T, c>::add(T* date)
{
  if(next>=size)
	  add_p();
  p[next++]=date;
 return date;

}
template <class T,int c>
void list<T,c>::count()const
{

	return next;
}
template <class T,int c>
T* list<T,c>::remove()
{
  if(next<=0)
	return NULL;
  T* s=p[--next];
  return s;

}
template <class T,int c>
T* list<T,c>::operator[](int index)const
{
   assert(index<next&&index>=0);
   return p[index];

}
template <class T,int c>
void list<T,c>::add_p()
{
 

   T** new_p=new T*[(size+c)];
   memset(new_p,0,sizeof(T*)*(size+c));
   memcpy(new_p,p,sizeof(T*)*(size));
   size+=c;
   delete []p;
   p=new_p;

 /*  void* s=malloc(sizeof(T*)*(size+c));
   memset(s,0,sizeof(T*)*(size+c));
   memcpy(s,p,sizeof(T*)*(size+c));
   size+=c;
   delete []p;
   p=(T**)s;*/
}
template <class T,int c>
list<T,c>::~list()
{ 
	while(next>0)
	  delete remove();
	delete []p;
}
