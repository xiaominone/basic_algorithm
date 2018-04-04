/*给定一个链表,翻转该链表从m到n的位置。
要求直接翻转而非申请新空间。
 如:给定1→2→3→4→5,m=2,n=4,返回
1→4→3→2→5。
 假定给出的参数满足:1≤m≤n≤链表长度*/

///解决方案 头插法
void reverse(snode* p,int from, int end)
{
    snode* cur = p->next;
    int i;
    for(i = 0;i < from-1; i++)
    {
        p = cur;
        p = p->next;

    }

    snode* pre = cur;
    cur = cur->next;

    end--;
    snode* pnext;

    ///头插法

    for(;i<end;i++)
    {
        pnext = cur->next;
        cur= pnext;
        pnext->next = pre->next;
        pre->next = pnext;

    }

}
