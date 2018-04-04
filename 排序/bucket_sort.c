///实现桶排序 （记数排序）
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 11 ///读10个数非0数
#define  max 1000
int main()
{
    int a[max+1],j;
    memset(a,0,sizeof(a));
    while(scanf("%d",&j)!=EOF)
    {
        a[j]++;
    }

    for(int k=1;k<N;k++)
    {
        if(a[k]!=0)
        {
            while(a[k]>0)
            {
                printf(" %d",k);
                a[k]--;

            }

        }
    }

    return 0;
}
