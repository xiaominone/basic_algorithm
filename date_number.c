//统计某一天是某年的第几天
#include<stdio.h>
typedef struct
{
    int months[12];
    int flag;
}year;
year n1={{31,29,31,30,31,30,31,31,30,31,30,31},0};
year n2={{31,28,31,30,31,30,31,31,30,31,30,31},1};
int main()
{
    int n,year,month,date;
    scanf("%d%d%d",&year,&month,&date);
    if(year%4==0 || year%100!=0&& year%400==0)
    {
        n = 0;
        for(int i=0;i<month-1;i++)
            n +=  n1.months[i];
        n += date;
    }

    else
    {
        n = 0;
        for(int i=0;i<month-1;i++)
            n += n2.months[i];
        n += date;
    }
    printf("%d",n);


    return 0;
}
