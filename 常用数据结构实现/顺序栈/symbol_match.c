/*
1.从前向后扫描字符串:
2.遇到左括号x,就压栈x;
3.遇到右括号y:
  3.1 如果发现栈顶元素x和该括号y匹配,则栈顶元素出栈,继续判断下一个字符。
  3.2 如果栈顶元素x和该括号y不匹配,字符串不匹配;
  3.3 如果栈为空,字符串不匹配;
4.扫描完成后,如果栈恰好为空,则字符串匹配,否则,字符串不匹配*/

bool isleft(char c)
{
    return (c=='(')||(c=='{')||(c=='[');

}

bool ismatch(char a,char s)
{
    if(s=='(')
        return s==')';
    if(s=='[')
        return s==']';
    if(s=='{')
        return s=='}';
    return false;
}

bool match_symbol(const char* p)
{
    stack<char>s;
    char cur;
    while(*p)
    {
        cur = *p;
        if(isleft(cur))//左括号
        {
            s.push(cur);
        }
        else
        {
            if(!ismatch(s.top(),cur)||s.empty())
                return false;
            s.pop()
        }
        p++;
    }
    return s.empty()///空表示匹配成功

}
