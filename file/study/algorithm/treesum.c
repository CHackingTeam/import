#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1024

struct node

{
    struct node* left;
    struct node* right;
    int data;
};
typedef struct node tree_node;
tree_node* root=NULL;

void insert_tree(tree_node** Root,int data)
{
   if((*Root)==NULL)
   {
     (*Root)=(tree_node*)malloc(sizeof(struct node));
     (*Root)->data=data;
     (*Root)->left=NULL;
     (*Root)->right=NULL;
   }
   else if((*Root)->data<data)
       insert_tree(&((*Root)->right),data);
   else
       insert_tree(&((*Root)->left),data);

}
void print_tree(int* arr,int depth)
{
   while(depth>=0)
       printf("%d\t",arr[depth]),depth--;
   printf("\n");
}
int sum(int* arr,int depth,int data)
{
    int sume=0;
    while(depth>=0)
        sume+=arr[depth],depth--;
    if(sume==data)
        return 1;
    else
        return 0;
}
void searchnum(tree_node* root,int* arr,int depth,int data)
{
    
    if(root!=NULL)
    {
    arr[depth]=root->data;
    if(sum(arr,depth,data)&&root->left==NULL&&root->right==NULL)
         print_tree(arr,depth);

    searchnum(root->left,arr,depth+1,data);
    searchnum(root->right,arr,depth+1,data);
    }

}
int main(int argc,char** argv)
{
    
    insert_tree(&root,10);
    insert_tree(&root,5);
    insert_tree(&root,12);
    insert_tree(&root,4);
    insert_tree(&root,7);
    int arr[MAXLINE];
   searchnum(root,arr,0,22);


    return 0;
}
