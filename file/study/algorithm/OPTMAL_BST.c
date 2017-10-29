#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
#define MAX 1024

void print_tree(int *c,int ci)
{
 if(c[ci]!=0)
 {
   printf("k%d_",c[ci]);
   print_tree(c,ci*2);
   print_tree(c,ci*2+1);
 }
}
void buile_tree(int left,int right,int root[][SIZE+1],int *c,int ci)
{
    
int rootp=root[left][right];
c[ci]=rootp;
if(left<right){
buile_tree(left,rootp-1,root,c,ci*2);
buile_tree(rootp+1,right,root,c,ci*2+1);

}
}
void OPTMAL_BST(float* d,float* q)
{
   int j;
   float t;
   float E[SIZE+2][SIZE+1];
   float W[SIZE+2][SIZE+1];
   int ROOT[SIZE+1][SIZE+1];
   int c[MAX];
   for(int i=0;i<1024;i++)
       c[i]=0;

   for(int i=1;i<=SIZE+1;i++)
       W[i][i-1]=q[i-1],E[i][i-1]=q[i-1];

   for(int l=1;l<=SIZE;l++)
       for(int i=1;i<=SIZE-l+1;i++)
       {
         j=i+l-1;
         E[i][j]=10000.0;
         W[i][j]=W[i][j-1]+d[j]+q[j];
         for(int r=i;r<=j;r++){
             t=E[i][r-1]+E[r+1][j]+W[i][j];
             if(t<E[i][j]){
                 E[i][j]=t;
                 ROOT[i][j]=r;
             }
         }
         if(l==SIZE&&i==1&&j==SIZE)
         printf("(i=%d,j=%d),R=%d,e=%f\n",i,j,ROOT[i][j],E[i][j]);
       }


   buile_tree(1,5,ROOT,c,1);
   print_tree(c,1);
   printf("\n");

}


int main(int argc,char** argv)
{

  float keyworld_rate[SIZE+1]=     {0.0,0.15,0.10,0.05,0.10,0.20};
  float world_rate[SIZE+1]   =     {0.05,0.10,0.05,0.05,0.05,0.1};
  OPTMAL_BST(keyworld_rate,world_rate);


    exit(0);
}
