#include <stdio.h>
#include <stdlib.h>

#define MAX 100000000
#define SIZE 14
void dl(int s[][SIZE+1],int i,int j)
{
   if(i==j)
       printf("A%d",i);
   else{
       printf("(");
       dl(s,i,s[i][j]);
       dl(s,s[i][j]+1,j);
       printf(")");
   }
}

int MATRIX_CHAIN_ORDER()
{
    
    int c=0;
    int j;
    int n=SIZE;
    int m[n+1][n+1];
    int s[n+1][n+1];

    int p[]={5,6,2,9,7,6,9,4,5,7,5,3,4,5,6};

    for(int i=1;i<=n;i++)
       m[i][i]=0; 
    
    for(int l=2;l<=n;l++)
        for(int i=1;i<=n-l+1;i++)
        {
            j=i+l-1;
            m[i][j]=MAX;
            for(int k=i;k<j;k++)
            {
            printf("m[%d][%d]+m[%d][%d]+p[%d]*p[%d]*p[%d]=%d+%d+%d*%d*%d\n",i,k,k+1,j,i-1,k,j,m[i][k],m[k+1][j],p[i-1],p[k],p[j]);
         
             c=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
           //  printf("%d\t",c);
             if(c<m[i][j])
             {
                 m[i][j]=c;
                 s[i][j]=k;
             }
            }
        }
  
  printf("min_size=%d\n",c);

  dl(s,1,n);
printf("\n");

}



int main(int argc,char** argv)
{
   
    MATRIX_CHAIN_ORDER();


    exit(0);
}
            
