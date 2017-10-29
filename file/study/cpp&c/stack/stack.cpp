#include "pstack.h"

template <class T> T* pstack<T>::push(T* dete)
 {
    struct link* p=new struct link(dete,haed);
    haed=p;
    return p->dete;
 }
template <class T> T* pstack<T>::peek()const
{
    if(haed==NULL)
       return 0;
   return haed->dete;    
}
template <class T> T* pstack<T>::pop()
 {
     if(haed==NULL)
         return NULL;
     T* p=haed->dete;
     struct link* l=haed;
     haed=haed->next;
     delete l;
     
     return p;
 }
 template <class T>
 pstack<T>::~pstack()
 {
     while(haed)
         delete pop();
}

