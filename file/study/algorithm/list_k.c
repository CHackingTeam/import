#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int m_nKey;
    struct ListNode* m_pNext;
};

typedef struct ListNode  node;

node* head=NULL;

void BuildList(int *a,int size)
{
    node* p=head;
for(int i=0;i<=size;i++)
{
   
   head=(node*)malloc(sizeof(struct ListNode));
   head->m_nKey=a[i];
   head->m_pNext=p;
   p=head;

}
}

void print_List_K(node* hp,int k)
{

static int c=0;
if(hp!=NULL){
   print_List_K(hp->m_pNext,k);
   if(c==k)
       printf("K=%d",hp->m_nKey);
   c++;
}
}
int main(int argc,char** argv)
{

int a[]={12,45,56,23,7,23,9};

BuildList(a,6);
print_List_K(head,5);



    exit(0);
}
