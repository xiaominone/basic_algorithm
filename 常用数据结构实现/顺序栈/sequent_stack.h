///顺序栈的实现 ///模拟一个10进制转换为8进制
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct sequent_stack ///顺序栈的管理结构体
{
    int *stack; ///顺序栈放data的数组
    int size; ///顺序栈的size   链栈没有size
    int top; ///顺序栈的栈顶下标
};

struct sequent_stack  *init_stack(int size)  ///初始化一个size大的空栈
{
    struct sequent_stack *s;
    s = malloc(sizeof(struct sequent_stack));///首先生成管理结构体

    if(s!=NULL)
    {
        s->stack = calloc(size,sizeof(int));///分配一个含有size个元素空间的整形数组
        s->size = size;
        s->top = -1;
    }
    return s;
};

bool stack_full(struct sequent_stack *s)
{
    return s->top>=s->size-1;
}

bool push(struct sequent_stack*s,int data)
{
    if(stack_full(s))///顺序栈判断是否满了
        return false;

    s->top++;
    s->stack[s->top] = data;
    return true;
}


bool stack_empty(struct sequent_stack *s)
{
    return s->top <= -1;
}

bool pop(struct sequent_stack *s,int *m)
{
    if (stack_empty(s))
        return false;

    *m = s->stack[s->top];
    s->top--;
    return true;

}




















