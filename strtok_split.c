/*当strtok()在参数s 的字符串中发现到参数delim 的分割字符时则会将该字符改为\0 字符。
在第一次调用时，strtok()必需给予参数s 字符串，往后的调用则将参数s 设置成NULL。
每次调用成功则返回下一个分割后的字符串指针*/
#include<string.h>
#include<stdio.h>
int main()
{
    char s[] = "ab-cd : ef;gh :i-jkl;mnop;qrs-tu: vwx-y;z";
    char *delim = "-: ";///定义分割符号种类
    char *p;
    printf("%s ", strtok(s, delim));///仅返回第一个分割字符串
    printf("\n********************\n");
    while((p = strtok(NULL, delim)))
    {///下次调用是使用NULL
        printf("%s ", p);
        printf("\n");

    }
 return 0 ;
}
