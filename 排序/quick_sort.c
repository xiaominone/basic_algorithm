#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define N 10
void quicksort(int *q,int left,int right)
{
    int i,j,t,k,temp;
    if(left>right)
        return ;

    i = left; j = right;
    //temp = q[left];///直接确定基准位置
    k=rand()%(right-left+1)+left;///随机确定基准位置
    temp = q[k];
    q[k] = q[i];
    q[i] = temp;



    while(i!=j)
    {
        while(q[j]>=temp&&i<j)///大于等于号
            j--;
        while(q[i]<=temp&&i<j)
            i++;
        if(i<j)
        {
            t=q[i];
            q[i]=q[j];
            q[j]=t;
        }
    }
    q[left]=q[i];
    q[i]=temp;

    quicksort(q,left,i-1);
    quicksort(q,i+1,right);
}




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


    quicksort(a,1,N);

    for(int k=1;k<=N;k++)
        printf("%d ",a[k]);


}
