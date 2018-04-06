/*给定一个链表和一个值x,将链表划分成两
部分,使得划分后小于x的结点在前,大于
等于x的结点在后。在这两部分中要保持原
链表中的出现顺序。
 如:给定链表1→4→3→2→5→2和x = 3,返回
1→2→2→4→3→5。*/

///分别申请两个指针p1和p2,小于x的添加到p1中,大于等于x的添加到p2中;最后,将p2链接到p1的末端

void partition(snode* phead, int value)//含有头节点的
{
    snode* f1 = new snode(0);
    snode* f2 = new snode(0);
    snode* f1head = f1;
    snode* f2head = f2;

    f1->next = null;
    f2->next = null;

    p = phead->next;
    while(p)
    {
        if(p->value < value)
        {
            f1->next = p;
            f1 = p;
        }
        else
        {
            f2->next = p;
            f2 = p;
        }
        p = p->next;
    }

    ///将2个链表连接
    f1->next = p2head->next;
    f2->next = null;

    phead->next = f1head->next;

    delete f1head;
    delete f2head;


}
