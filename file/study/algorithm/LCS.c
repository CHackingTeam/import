#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

int m[SIZE][SIZE];
char b[SIZE][SIZE];

void LCS(char *cs1,char *cs2)
{
  char x;
  char y;

  for(int i=1;i<SIZE;i++)
       m[i][0]=0,m[0][i]=0,b[i][0]='/',b[0][i]='/';
  for(int j=1;j<SIZE;j++)
  {
        x=cs2[j-1];
        y=cs1[0];
    for(int i=1;i<SIZE;i++)
    {
        y=cs1[i-1];
       if(x==y)
           m[j][i]=m[j-1][i-1]+1,b[j][i]='|';
       else if(m[j-1][i]>m[j][i-1])
           m[j][i]=m[j-1][i],b[j][i]='/';
       else
           m[j][i]=m[j][i-1],b[j][i]='*';
    }
  }


}

void print_LCS(char *x,int j,int i)
{
    if(i==0||j==0)
        return;
    if(b[j][i]=='|'){
      print_LCS(x,j-1,i-1);
      printf("%c",x[i-1]);
        
    }
    else if(b[j][i]=='/')
        print_LCS(x,j-1,i);
    else
        print_LCS(x,j,i-1);

}

void print(int j,int i)
{
  if(b[j][i]=='|')
      printf("↖");
  else if(b[j][i]=='/')
      printf("↑");
  else
      printf("←");


}
void print_table_lcs(char* lcs1,char* lcs2,int x,int y)
{
    for(int k=0;k<7;k++){
    for(int i=0;i<x;i++)
        if(k>0&&i>0)
           printf("*---");
        else if(k==0)
            printf("");
        else
           printf("    ");
        if(k>0)
        printf("*\n");
    for(int j=0;j<y;j++)
        if(j==0&&k>=2)
            printf("  %c ",lcs2[k-2]);
    else if(k==0&&j>=2)
            printf("  %c ",lcs1[j-2]);
    else if(k>=1&&j>=1)
            printf("|%d-",m[k-1][j-1]),print(k-1,j-1);
        else
            printf("    ");
    if(k>0)
      printf("|\n");
    else
        printf("\n");
    }



}

     


int main(int argc,char** ragv)
{

   char cs1[]={'H','P','C','D','H'};
   char cs2[]={'B','P','V','C','D'};

   LCS(cs1,cs2);
   
   printf("\nLCS:");
   print_LCS(cs1,5,5);
   printf("\n");


   print_table_lcs(cs1,cs2,7,7);


    exit(0);
}
