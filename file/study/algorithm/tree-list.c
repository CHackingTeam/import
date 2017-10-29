/*************************************************************************
    > File Name: tree-list.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年05月10日 星期二 20时49分33秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
   int date;
   struct tree* left;
   struct tree* hight;

} *Tree;
Tree min(Tree p)
{
   if(p->left==NULL)
	  return p;
  return min(p->left);
}
void tree_list(Tree* root,Tree* left_hight)
{
   

    if((*left_hight)!=NULL)
	{
    	tree_list(*root->left,*left_hight->left);
    	tree_list(*root->hight,*left_hight->hight);
	}
   
 





}


int main(int argc,char** argv)
{





	exit(0);
}
