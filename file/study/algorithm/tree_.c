#include <stdio.h>
#include <stdlib.h>
#define MAX_NODE 1024

struct node

{
    struct node* left;
    struct node* right;
    int data;
};
typedef struct node tree_node;
tree_node* root=NULL;

tree_node* queue[MAX_NODE];
int queue_head=0;
int queue_top=0;
int queue_size=0;

void queue_push(tree_node* d)
{
    queue[queue_head]=d;
    queue_head++;
    queue_size++;
}
tree_node* queue_pop()
{
    queue_size--;
    queue_top++;
    return queue[queue_top-1];
}

int empty()
{
    if(queue_size==0)
        return 0;
    else
        return 1;
}

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

int main(int argc,char** argv)
{
 
    tree_node* p;
    insert_tree(&root,8);
    insert_tree(&root,6);
    insert_tree(&root,10);
    insert_tree(&root,5);
    insert_tree(&root,7);
    insert_tree(&root,9);
    insert_tree(&root,11);

    queue_push(root);

    while(empty())
    {
       p=queue_pop();
       printf("%d:",p->data);
       if(p->left!=NULL)
           queue_push(p->left);
       if(p->right!=NULL)
           queue_push(p->right);
    }
   printf("\n");

    exit(0);
}
    
