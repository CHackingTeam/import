#include <stdio.h>
#include <stdlib.h>

struct BSTTreeNode
{
    int m_nValue;
    struct BSTTreeNode *m_pLeft;
    struct BSTTreeNode *m_pRight;
};

typedef struct BSTTreeNode tree_node;
tree_node* root=NULL;
void insert_tree(tree_node** Root,int data)
{
   if((*Root)==NULL)
   {
     (*Root)=(tree_node*)malloc(sizeof(struct BSTTreeNode));
     (*Root)->m_nValue=data;
     (*Root)->m_pLeft=NULL;
     (*Root)->m_pRight=NULL;
   }
   else if((*Root)->m_nValue<data)
       insert_tree(&((*Root)->m_pRight),data);
   else
       insert_tree(&((*Root)->m_pLeft),data);

}

void print(tree_node* root)
{

    if(root)
    {
      printf("%d\t",root->m_nValue);
      print(root->m_pLeft);
      print(root->m_pRight);
    }
}
void swp_tree(tree_node** root)
{

if(*root!=NULL)
{
  swp_tree(&((*root)->m_pLeft));
  swp_tree(&((*root)->m_pRight));
  tree_node* p=(*root)->m_pLeft;
  (*root)->m_pLeft=(*root)->m_pRight;
  (*root)->m_pRight=p;
}
}

int main(int argc,char** argv)
{
   insert_tree(&root,8);
   insert_tree(&root,6);
   insert_tree(&root,10);
   insert_tree(&root,5);
   insert_tree(&root,7);
   insert_tree(&root,9);
   insert_tree(&root,11);

   print(root);
   printf("\n");
   swp_tree(&root);
   print(root);
   printf("\n");





    exit(0);
}
