#ifndef PSTACK_H
#define PSTACK_H
#include <stdio.h>
#include <iostream>
template <class T>
class pstack
{
private:
    struct link
    {
        T* dete;
        struct link* next;
        link(T* dete,struct link* next):dete(dete),next(next){}
    } *haed;

public:
    pstack():haed(0){}
    T* push(T* dete);
    T* peek()const;
    T* pop();
    ~pstack();
    class iterator;
    friend class iterator;
    class iterator
    {
    private:

       pstack::link* itp;
    public:

        iterator(const pstack<T>& c):itp(c.haed){}
        iterator(const iterator& it)
        {
            itp=it.itp;
        }

      /*  iterator operator=(iterator it)
        {
            itp=it.itp;
            return iterator(this);
        }*/
        T* current()const
        {
            if(itp==NULL)
                return 0;
            return itp->dete;

        }

       bool operator++()
       {
        if(itp->next==NULL)
            return 0;
        itp=itp->next;
            
        return bool(itp);
       }
       T* operator*()
       {
           return current();
           
       }
       T* operator->()
       {
           return current();
       }
       bool operator!=(const iterator&)
       {
           return itp!=0;
       }
    };
       iterator begin()const
       {
          iterator(*this);
       }

       iterator end()const
        {

           return iterator();
       
        }
    
};


#endif // PSTACK_H

