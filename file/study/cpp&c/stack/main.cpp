#include <iostream>
#include "pstack.h"
#include "stack.cpp"
using namespace std;

int main()
{
    pstack<int> c;
    int i=0;
    int *p;
    for(;i<10;i++){
        p=new int(i);
        c.push(p);
    }
    pstack<int>::iterator start(c);
    ++start;
    cout<<*(*start)<<"\n"<<endl;








    cout << "Hello World!" << endl;
    return 0;
}

