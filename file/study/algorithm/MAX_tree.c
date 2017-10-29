#include <stdio.h>
#include <stdlib.h>

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

void max_(tree_node* root,int i,int* c)
{ 
  
 
  if(root!=NULL)
  {  
      i++;
      if(i>*c)
          *c=i;
      max_(root->left,i,c);
      max_(root->right,i,c);
  }
}
void MAX_node(tree_node* root,int* m)
{ 
   
  if(root!=NULL)
  {
   int max_left=0;
   int max_right=0;
   int max=0;


   MAX_node(root->left,m);
   MAX_node(root->right,m);
   max_(root->left,0,&max_left);
   max_(root->right,0,&max_right);
   max=max_right+max_left;
   if(*m<max)
       *m=max;
  }
}


int main(int argc,char** argv)
{

    int m=0;
    int m1=0;
    insert_tree(&root,10);
    insert_tree(&root,5);
    insert_tree(&root,12);
    insert_tree(&root,4);
    insert_tree(&root,7);
    insert_tree(&root,28);
    insert_tree(&root,27);
    insert_tree(&root,13);


    MAX_node(root,&m);
    printf("%d\n",m);




exit(0);


}
