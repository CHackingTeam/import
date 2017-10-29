//===============================================================
//            FreeBSD hello!!! 
//                 
//===============================================================

#include <stdlib.h>
#include <stdio.h>
#define MAX 10000000
int sorq_index;
int sorq_child(int l,int h,int *a)
{
  int i=l;
  int j;
  int exchang;
  for(j=l+1;j<h;j++)
    if(a[l]>=a[j])
    {
       i++;
       exchang=a[j];
       a[j]=a[i];
       a[i]=exchang;
    }
  exchang=a[l];
  a[l]=a[i];
  a[i]=exchang;

  return i;
}

void sorq(int left,int hight,int* a)
{
  
 if(left<=hight){
   sorq_index=sorq_child(left,hight,a);
   sorq(left,sorq_index-1,a);
   sorq(sorq_index+1,hight,a);
 }

}



int main(int argc,char* argv[])
{
 int a[MAX];
 int c;
 FILE* fp;
 if((fp=fopen("file.txt","w"))==NULL)
   printf("error open file.txt\n");
 for(c=0;c<MAX;c++)
    fprintf(fp,"%d\n",rand()%10000);
 fclose(fp);
 if((fp=fopen("file.txt","r"))==NULL)
    printf("error open fp\n");
 for(c=0;c<MAX;c++)
 { fscanf(fp,"%d\n",&a[c]);
   printf("%d\n",a[c]);
 }
 
 /*


 int c;
 int a[]={1,3,54,2,8};
 sorq(0,5,a);
 for(c=0;c<5;c++)
  printf("%d\t",a[c]);
 printf("\n");
 
*/
fclose(fp);
   return 0;
}
