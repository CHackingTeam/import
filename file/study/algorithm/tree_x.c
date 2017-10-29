#include <stdio.h>

int count=0;
struct tree
{
	struct tree* left;
	struct tree* right;
	int data;
	tree(struct tree *pl,struct tree* pr,int d):left(pl),right(pr),data(d){}
};

typedef struct tree Tree;

Tree a1(NULL,NULL,20);
Tree a0(NULL,NULL,21);
Tree a2(NULL,NULL,46);
Tree a3(NULL,NULL,70);
Tree a10(&a1,&a0,30);
Tree a23(&a2,&a3,47);
Tree a1023(&a10,&a23,45);



void tree_min_x(struct tree* root,int x)
{
	if(root==NULL)
	   return;
	if(root->data<x)
	   {
	    count++;
	    tree_min_x(root->right,x);
	   }	   
	   tree_min_x(root->left,x);
}
int main(int argc,char ** args)
{
	
	tree_min_x(&a1023,48);
	printf("%d\n",count);
 	
	
	
	
	
	return 0;
}
