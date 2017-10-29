#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;


int char_num(char peek)
{
	return (peek-'0');
}
int assert_num(char peek)
{
    if(peek>='0'&&peek<='9')
        return 1;
    else
        return 0;
}
int assert_char(char peek)
{
    if(peek>='a'&&peek<='z')
        return 1;
    else
        return 0;
}
class Token
{
   public:
       int tag;
       Token(int i):tag(i){}
};

class Tag
{
 public:
     int NUM=256,ID=257,TRUE=258,FALSE=259,IF=230,CONST=231,EQ=232,ASSIGN=233;
};

class Num :public Token
{
    public:
        int value;
        Num(int v):Token(Tag().NUM),value(v){}
};
class Worlds :public Token
{
    public:
        string name;
        Worlds(string s,int t):Token(t),name(s){}
};

class Lexer
{
   private:
       std::map<std::string,Worlds* > id_table;
       std::map<std::string,Worlds* > keyworlds_table;
       std::map<int ,std::string> operator_table;
       char peek;
       void reserve(Worlds* t)
       {
           keyworlds_table[t->name]=t;
       }
   public:
       int line;
       Lexer()
       {
           peek=' ';
           line=1;
           reserve(new Worlds("true",Tag().TRUE));
           reserve(new Worlds("false",Tag().FALSE));
           reserve(new Worlds("if",Tag().IF));
           reserve(new Worlds("=",Tag().ASSIGN));
           reserve(new Worlds("\\n",Tag().CONST));
           reserve(new Worlds("==",Tag().EQ));
           
           operator_table[Tag().ASSIGN]="assign";
           operator_table[Tag().CONST]="const";
           operator_table[Tag().EQ]="eq";

       }

       void print(int i)
       {
            


       }
       Token* scan()
       {
          for(;;peek=getchar())
          {
            if(peek==' '||peek=='\t')
               continue;
            else if(peek=='\n'){
               line+=1;
               return NULL;
               continue;
            }
            else
               break;
          }
          if(assert_num(peek))
          {
              int v=0;
              do
              {
                 v=v*10+char_num(peek);
                 peek=getchar();
              }while(assert_num(peek));
              Token* p=new Num(v);
              cout<<"<num,"<<v<<">"<<" ";
              return p;

          }
          else if(assert_char(peek))
          {
              string b="";
              do
              {
                 b=b+peek;
                 peek=getchar();
              }while(assert_num(peek)||assert_char(peek));
            if(keyworlds_table[b]!=NULL)
            {
                   cout<<"<"<<b<<">"<<" ";   
             return new Worlds(b,Tag().IF);
            }
            else
            {
                if(id_table[b]==NULL)
                    id_table[b]=new Worlds(b,Tag().ID);
                cout<<"<ID,"<<b<<">"<<" ";
            }
            return new Worlds(b,Tag().ID);
          }
          else
          {
              string b="";
              b.insert(0,1,peek);
              Token* p=new Token(peek);
              if(keyworlds_table[b]!=NULL)
                  cout<<"<"<<operator_table[keyworlds_table[b]->tag]<<">"<<" ";
              else
                  printf("<%c>",p->tag);
          peek=' ';
          return p;
          }
       }


};

int main(int argc,char** args)
{

cout<<"hi"<<"\n"<<endl;
Lexer* lex=new Lexer();
Token* p=NULL;
while(1)
{
   p=lex->scan();
   if(p==NULL)
       break;
}
cout<<"\n";

	return 0;
}

