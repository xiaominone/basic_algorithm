/*
中缀表达式:a+(b-c)*d  后缀表达式:abc-d*+
逆波兰表达式 （树的后缀遍历）


问题：计算给定的逆波兰表达式的值
*/

///解析：
///若当前字符是操作数,则压栈
///若当前字符是操作符,则弹出栈中的两个操作数,计算后仍然压入栈中
  ///（ 若某次操作,栈内无法弹出两个操作数,则表达式有误）


char*ch[10]={'1','2','*','3','-'};///考虑指针数组存

bool isoperator(const char* s)
{
    return ((*s)=='+') || ((*s)=='-') || ((*s)=='*') || ((*s)=='/');

}

int rever_polish(const char*str[]; int size)///参数为指针数组
{
    stack<int>s;
    int a,b;
    const char* tok;

    for(int i =0;i<size;i++)
    {
        tok = str[i];
        if(!isoperator(tok))
            s.push(*tok);
        else
        {
            b = s.top();
            s.pop();
            a = s.top();
            s.pop();
            if(*tok=='+')
                s.push(a+b);
            else if(*tok=='-')
                s.push(a-b);
            else if(*tok=='*')
                s.push(a*b);
            else
                s.push(a/b);
        }
        return s.top();
    }
}
