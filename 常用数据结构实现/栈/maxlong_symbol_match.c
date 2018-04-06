///给定字符串,仅包含左括号‘(’和右括号‘)’,设计算法,找出最长匹配的括号子串,返回该子串的长度

///egg:(():2
///()():4
///()(()):6
///(()()):6


///解析1：
/*记起始匹配位置start=-1;最大匹配长度ml=0:
考察第i位字符c:
   1.如果c为左括号,压栈;
   2.如果c为右括号,它一定与栈顶左括号匹配;
      2.1如果栈为空,表示没有匹配的左括号,start=i,为下一次可能的匹配做准备
      2.2如果栈不空,出栈(因为和c匹配了);
         2.2.1 如果栈为空,i-start即为当前找到的匹配长度,检查i-start是否比 ml更大,使得ml得以更新;
         2.2.2 如果栈不空,则当前栈顶元素t是上次匹配的最后位置,检查i-t是否比ml更大,使得ml得以更新。
 */

///注:因为入栈的一定是左括号,显然没有必要将它们本身入栈,应该入栈的是该字符在字符串中的索引

int getlongest_symbolmatch1(const char* p)
{
    int size = (int)sizeof(strlen(p));
    stack<int>s;
    int answer = 0;
    int start =-1;//左括号前面一个位置

    for(int i=0;i<size;i++)
    {
        if(p[i]=='(')
            s.push(i);//索引入栈
        else///扫描字符为右括号
        {
            if(s.empty())
                start = i;
            else
            {
                s.pop();///栈不为空 一定要出栈
                if(s.empty())
                    answer = max(answer,i-start);///出栈之后为空 记录总长度
                else
                    answer = max(answer,i-s.top());///出栈之后不为空，当前栈顶元素为其括号起始位置的前一个位置
            }
        }
    }

    return answer;

}





///解析2：
/*1.只有在右括号和左括号的发生匹配时,才有可能更新最终解;
  2.做记录前缀串p[0...i-1]中左括号数目与右括号数目的差x,若x为0时,考察是否最终解得以更新即可。这个差x,其实是入栈的数目,代码中用“深
度”deep表达;
  3.由于可能出现左右括号不相等——尤其是左括号数目大于右括号数目,所以,再从右向前扫描一次。
这样完成的代码,用deep值替换了stack栈,空间复杂度由O(N)降到O(1)

*/

int getlongest_symbolmatch2(const char* p)
{
    int size = (int)sizeof(strlen(p));
    int answer = 0;
    int deep=0;///遇见多少个无法抵消的左括号（右括号）
    int start = -1;///方便计算 最深左（右）括号的前（后）一位


    int i;
    for(int i=0;i<size;i++)
    {
        if(p[i]=='(')
        {
            deep++;
        }
        else///右括号
        {
            deep--;
            if(deep==0)
                answer = max(answer,i-start);
            else if(deep<0)///右括号多
            {
                deep =0;
                start = i;///重新定义开始位置
            }
        }
    }

    deep = 0;
    start = size;

    for(i = size-1;i>=0;i--)
    {
        if(p[i]==')')
            deep++;
        else
        {
            deep--;
            if(deep==0)
            {
                answer = max(answer,start-i);
            }
            else if(deep<0)///左括号大于右括号的数目
            {
                deep =0;
                start = i;
            }
        }

    }

    return answer;
}










