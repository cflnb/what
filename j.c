#include<stdio.h>
int a[6]={0,0,0,0,0,0};
int b[6]={1,2,3,4,5,6};
int i;
int c=0;

int main()

{   while(c!=10)
    {
    for(i=0;i<6;i++)
    {
    scanf("%d",&c);
    a[i]=c;
    }
    }
    for(i=0;i<6;i++)
    {
        if（a[i]!=b[i]）
        {
            printf("A");
            continue;
        }
        else
        {
            printf("B");
        }
    }
    
    return 0;
}
