/*给定两个链表,分别表示两个非负整数。它
们的数字逆序存储在链表中,且每个结点只
存储一个数字,计算两个数的和,并且返回
和的链表头指针。
 如:输入:2→4→3、5→6→4,输出:7→0→8*/

#include<stdio.h>
#include<stdlib.h>

addnode* add(snode* pre1,snode* pre2)
{
    snode* sum  = new snode(0);
    snode* p = sum;
    snode* p1 = pre1->next;
    snode* p2 = pre2->next;
    snode* cur;
    int car=0,val;
    while(p1 && p2)
    {
        val = p1->value + p2->value+car;
        car = val/10;///统计进位
        val = val%10;

        cur = new snode(val);

        p->next = cur;
        p = cur;

        p1 = p1->next;
        p2 = p2->next;

    }
    ///处理长链
    snode* s=  p1 ? p1 : p2;
    while(s)
    {
        val = s->value+car;
        car = val/10;
        val = val%10;

        cur = new snode(val);

        p->next = cur;
        p = cur;

        s = s->next;

    }

    if(car!=0)
    {
        p->next = new snode(car);
    }

}




