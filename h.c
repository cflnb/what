#include <stdio.h>
#include <stdlib.h>
#include "lianbiao.h"
Sq*head[1001];
int main()
{
    int m,n,i,x,y;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    InitList(&head[i]);
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        ListInsert(head[x],ListLenth(head[x])+1,y);
    }
    for(i=1;i<=n;i++)
    DispList(head[i]);
    return 0;
}