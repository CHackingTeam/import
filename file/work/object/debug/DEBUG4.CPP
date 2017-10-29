#include <iostream>
#include <string>
using namespace std;
class dog
{
  string dog_name;
  int count;
 public:
  dog(const dog& d,int c=0)
  {
    cout<<"call dog(const dog&)\n"<<endl;
     count=c;
     dog_name=d.dog_name;
  }
  dog(const string& str):dog_name(str){
  count=0;
  }
 int add_dog()
 {
  cout<<"print count"<<count+1<<"\n"<<endl; 
  return ++count;

 }
int delete_dog()
{
 cout<<"print caount"<<count-1<<"\n"<<endl;
 if(--count==0)
   delete (this);
  return count;
}

dog* retdog(const string & str)
{
  if(count==1)
    {
      this->dog_name=str;
      return this;
    }
  this->delete_dog();
  return (new dog(str));


}
~dog()
{}
};
class fundog
{
 dog* p_dog;
 string fun_name;
public:
 fundog(const fundog& fun)
 {
   cout<<"call fundog(const fundog& )\n"<<endl;
   p_dog=fun.p_dog;
   fun_name=fun.fun_name+"funmane";
   p_dog->add_dog();
 }
 fundog(dog* p,string str):fun_name(str)
  {
  
    cout<<"call fundog(dog* ,string )\n"<<endl;
    p_dog=p;
    p_dog->add_dog();

  }
 fundog operator=(const fundog& fun)
 { 
   p_dog->delete_dog();
   fun_name=fun.fun_name;
   p_dog->add_dog();   
  return (*this);

 }

void uname(const string& str)
{
  p_dog=p_dog->retdog(str);
  fun_name="new funname";
  cout<<"call uname(const string& ) fun_name=\t"<<fun_name<<"\n"<<endl;    

}
~fundog()
{}

};
int main(int argc,char* argv[])
{

 dog Mdog("caocong");
 fundog fun1(&Mdog,"fundog");
 fundog fun2=fun1;
 fun1.uname("freebsd hello!");
 




  return 0;
}
