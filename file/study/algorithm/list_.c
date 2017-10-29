#include <stdio.h>
#include <stdlib.h>
struct list_
{
    int data;
    struct list_* next;
};

typedef struct list_ list;

list* root=NULL;
void insert(int data)
{
    list* p=(list*)malloc(sizeof(struct list_));
    p->data=data;
    p->next=root;
    root=p;
}
void print()
{
 list* p=root;
 while(p){
    printf("%d\t",p->data);
    p=p->next;
 }
 printf("\n");

}

void swap_list()
{
  list* next_;
  list* top=root->next;
  list* head=root;

 for(;top!=NULL;head=top,top=next_){
  next_=top->next;
  top->next=head;
 }
 root->next=NULL;
root=head;
}

int main(int argc,char** argv)
{

insert(10);
insert(9);
insert(5);
insert(4);
print();
swap_list();
print();
    exit(0);
}
