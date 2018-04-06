#include <stdio.h>
#include "link_stack.h"
int main(void)///模拟一个10进制转换为8进制
{
    struct link_stack *s;
    s = init_stack();

    int n;
    scanf("%d",&n);

    while(n>0)
    {
        int c = n%8;
        struct node *p = new_node(c);
        push(s,p);
        n/=8;
    }

    //int *m,*t;
    //printf("%d\n",s->top->data);
    //printf("%d\n",--(s->top)->data);
    //pop(s,m);

    //printf("%d\n",*m);

    int *m;
    /*while(!stack_empty(s))
    {
        pop(s,m);
        //printf("%d",*m);
    }
    */
    printf("\nhello");
    return 0;
}
