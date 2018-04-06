#ifndef LINK_STACK__H_INCLUDED
#define LINK_STACK__H_INCLUDED
///链栈的实现
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node ///链栈节点的结构体
{
    int data;
    struct node *next;
};

struct link_stack ///栈管理结构体 关注栈顶指针 、栈的size
{
    struct node *top;///栈顶节点
    int size;
};

struct link_stack *init_stack(void)///链栈不用制定栈的大小 初始化为0即可
{
    struct link_stack *s;
    s = malloc(sizeof(struct link_stack));///生成管理结构体

    if (s != NULL)
    {
        s->size = 0;
        s->top = NULL;
    }

    return s;

};


struct node *new_node(int data)///生成一个节点
{
    struct node *new;
    new = malloc(sizeof(struct node));
    if(new != NULL)
    {
        new->data = data;
        new->next = NULL;
    }
   return new;
};

bool push(struct link_stack *s,struct node *new)
{
    if(s == NULL || new == NULL )
        return false;
    new->next = s->top;
    s->top = new;
    s->size++;

    return true;
}

bool stack_empty(struct link_stack *s)
{
    if((s == NULL) || (s->size <= 0))
        return true;
}


bool pop(struct link_stack *s,int *p)
{
    if(stack_empty(s))
        return false;

    struct node *tmp = s->top;
    *p = tmp->data;

    s->top = s->top->next;
    free(tmp);
    s->size--;

    return true;

}

#endif // LINK_STACK__H_INCLUDED
