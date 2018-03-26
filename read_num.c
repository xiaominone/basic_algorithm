#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NUMBER 100000
#define MIN_NUMBER -100000

int main()
{
    char *ch[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    char *Read[6];
    //char b[10];

    int i=0;
    int read_number;
    scanf("%d",&read_number);
    if(read_number > MAX_NUMBER || read_number < MIN_NUMBER)
        return ;
    while(read_number>0)
    {
        //Read[i] = malloc(sizeof(int)*strlen(ch[read_number%10]));///针对不同的字符串申请相应的空间大小  （考虑空间）
        Read[i] = malloc(sizeof(ch[read_number%10])/sizeof(char));///针对不同的字符串申请相应的空间大小  （考虑空间）

        strcpy(Read[i++],ch[read_number%10]);
        //printf("%s ",Read[0]);
        read_number/=10;
        //printf("%d",read_number);
    }

    for(int j=i-1;j>-1;j--)
        printf("%s\n",Read[j]);

    return 0;
}
