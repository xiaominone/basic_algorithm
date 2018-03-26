#include <stdio.h>
#include "sequent_stack.h"
int main(void)///模拟一个10进制转换为8进制
{
    struct sequent_stack *s;
    s = init_stack(10);

    int n;
    scanf("%d",&n);

    while(n>0)
    {

        push(s,n%8);
        n/=8;
    }

    int *m;
    while(!stack_empty(s))
    {
        pop(s,m);
        printf("%d",*m);
    }
    printf("\nhello");
    return 0;
}
