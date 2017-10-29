#ifndef PLIST_H
#define PLIST_H
#include <iostream>
#include <cassert>
using namespace std;
template <class T,int c=20>
class list
{
	private:
		int next;
		int size;
		T** p;
	public:
		list():p(0),next(0),size(0){}
		T* add(T* date);
		void count()const;
		T* remove();
		T* operator[](int index)const;
		void add_p();
		class iterator;
		friend class iterator;
		class iterator
		{
			private:
			    list& itp;
				int index;
            public:
			//	iterator():itp(0){}
				iterator(list<T>& l):itp(l),index(0){}
                iterator(const list<T>& l,bool ):itp(l),index(l.next){}
				iterator operator++()
				{
				    assert(index<itp.next);
					index++;
					return iterator(*this);
				}
                iterator operator++(int)
				{
                    assert(index<itp.next);
					iterator a(*this);
					index++;
					return a;

				}
				T* current()const
				{

					if(index<0&&index>=itp.next)
					  return NULL;
					return itp.p[index];
				}
				T* operator*()
				{
		

                   return current();
				}
                T* operator->()
				{
                      return current();
				}
          };
		iterator begin()
		{
			iterator(*this);
		}
		iterator end()
		{
			iterator(*this,0);
		}
		~list();
		

};


#endif //PLIST_H
