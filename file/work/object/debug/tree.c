#include <stdio.h>
#include <stdlib.h>
typedef struct node* ptree
struct node
{
  int size;
  ptree left;
  ptree right;
};

ptree root;
int insert(ptree& root,int item);
void print(ptree root);
void tree_link(ptree& root);
int main()
{


return 0;
}

int insert(ptree& root,int item)
{
  if(root==NULL)
  {
     root=(ptree)malloc(sizeof(struct node));
     root->size=item;
     root->left=NULL;
     root->right=NULL;
     return root->size;

   }
  else if(root->size>item)
      insert(root->left,item);
  else if(root->size<item)
      insert(root->right,item);
}
void print(ptree root)
{
  if(root!=NULL)
{

  print(root->left);
  print(root->right);
  printf("%d\t",root->size);

}
}
ptree tree_hight(ptree p)
{
  




}
void tree_link(ptree& root_y,ptree& root_x)
{
      









}
