#include <stdio.h>
#include <math.h>

int main()
{   
     int high[16]={0};
    int low[16]={0};
    int i=31,num=0,k=0;
  int sum;
    scanf("%d",&num);
    while (i>=16)
    {
        low[k]=num/(int)pow(2,i);
        num=num%(int)(pow(2,i));
        k++;
        i--;
    }
    k=0;
    while(i>=0)
    {
      high[k]=num/(int)pow(2,i);
        num=num%(int)(pow(2,i));
        i--;
        k++;
    }
    i=31;k=0;
   while(i>=16)
   {
       sum+=high[k]*(int)pow(2,i);
       i--;
       k++;
   }
   k=0;
   while(i>=0)
   {
       sum+=low[k]*(int)pow(2,i);
       i--;
       k++;
   }

   printf("%d",sum);
}