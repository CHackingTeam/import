#include <stdio.h>
#include <stdlib.h>

#define  MAX(nu1,nu2,nu3) (nu1>nu2?nu1:nu2)>nu3?(nu1>nu2?nu1:nu2):nu3

void print_(int* aq,int left,int c,int right)
{

    for(int i=0;i<=5;i++)
            printf("%d ",aq[i]);
     printf("\n");
    

     for(int i=0;i<=c;i++)
         printf("  ");
     printf("^\n");
}

int find_max(int* aq,int left,int i,int right)
{
   print_(aq,left,i,left);
   int left_=0;
   int right_ =0;
   int left_count;
   int right_count;
   int count=0;
   for(int j=i;j>left;j--)
       if(j==i)
       left_count=aq[j]-aq[j-1],left_++;
       else
           if(left_count==(aq[j]-aq[j-1]))
               left_++;
           else
               break;
   for(int j=i;j<right;j++)
       if(j==i)
           right_count=aq[j+1]-aq[j],right_++;
       else
           if(right_count==(aq[j+1]-aq[j]))
               right_++;
           else
               break;

   if(left_count==right_count)
       count=left_+right_;
   if(count>=2||left_>=2||right_>=2)
       printf("yse\n");


  return MAX(count,left_,right_);
}

int dengcha_max(int* aq,int left,int right)
{
 if(left>=right)
    return; 
 else{
    int i=(left+right)/2;
    find_max(aq,left,i,right);
    dengcha_max(aq,left,i-1);
    dengcha_max(aq,i+1,right);
    }
}

void dengcha_max2(int *aq,int size)
{
   
    int cout=1;
    int save=aq[0]-aq[1];
    for(int i=1;i<size;i++)
        if(save==(aq[i]-aq[i+1])){
            if((++cout)>=2){
                printf("yes\n");
                return;
            }
        }
        else
            save=aq[i]-aq[i+1],cout=1;
            
   
    printf("NO");
}
int main(int argc,char** argv)
{
  int aque[]={12,13,14,1,6,7};

   
   //dengcha_max2(aque,5);

   dengcha_max(aque,0,5);
    exit(0);
}
