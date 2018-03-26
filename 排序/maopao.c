///从a[1]开始存储元素
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define N 10

int main()
{
    int a[N+1],i,j,t;
    srand(time(NULL));
    for(int k=1;k<=N;k++)
    {
       a[k]= rand()%100;
    }
    for(int k=1;k<=N;k++)
        printf("%d ",a[k]);

    printf("\n");

    for(int i=1;i<=N-1;i++)///比较n-1趟
    {
        for(int j=1;j<=N-i;j++)
        {
            if(a[j] > a[j+1])
            {
                t=a[j+1];
                a[j+1]=a[j];
                a[j]=t;
            }
        }
    }
    for(int k=1;k<=N;k++)
        printf("%d ",a[k]);


}
