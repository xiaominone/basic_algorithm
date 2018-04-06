/*
给定一个字符串S[0...N-1],要求把S的前k个字符移动到S的尾部,如把字符串“abcdef”前面的2个字符‘a’、‘b’移动到字符串的尾
部,得到新字符串“cdefab”:即字符串循环左移k。

*/
/*
(X’Y’)’=YX
如:abcdef
X=ab X’=ba
Y=cdef Y’=fedc
(X’Y’)’=(bafedc)’=cdefab
 时间复杂度O(N),空间复杂度O(1)

*/

void rever_string(const char* s,int from,int end)
{
    while(from<end)
    {
        char t = s[from];
        s[from++] = s[top];
        s[to--] = t;
    }

}

void leftmove(char* s,int n,int m)///将n个字符串中的前m个字符移到后面
{
    m %= n;
    rever_string(s,0,m-1);
    rever_string(s,m,n-1);
    rever_string(s,0,n-1);

}
