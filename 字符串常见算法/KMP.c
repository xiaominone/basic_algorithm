/*
给定文本串text和模式串pattern,从文本串text中找出模式串pattern第一次出现的位置
*/

///BF算法的时间复杂度O(M*N),空间复杂度O(1)  KMP算法的时间复杂度O(M+N),空间复杂度O(M)


///暴力求解
int bf(const char* s,const char* p)
{
    int i = 0;//文本串匹配开始位置
    int j = 0;//模式串匹配开始位置
    int size = (int)strlen(p);
    int nlast = (int)strlen(s)-size;///i能取的最大值
    while((i<=nlast)&&(j<size))
    {
        if(s[i+j]==p[j])
        {
            j++;
        }
        else
        {
            i++;
            j=0;
        }
    }
    if(j>=size)
        return i;///返回文本串开始匹配位置
    return -1;

}

///kmp
/* 1.如果当前字符匹配成功,即text[i+j]== pattern[j],令j++,继续匹配下一个字符;
   2..如果失配,即text[i+j]≠pattern[j],令i不变,j=next[j],(这里,next[j]≤j-1),即模式串pattern相对于文本串text向右移动了至少1位(移动的实际位数j-next[j]≥1)
(不需要让模式串重头开始)
*/

///kmp 求模式串的next
/*
计算next[j]时,考察的字符串是模式串的前j-1个字符,与pattern[j]无关
next[i],考察模式串[0,j)的最大相等前缀和后缀的个数
*/
///next 数组的递推关系

/*对于模式串的位置j,有next[j]=k,对于模式串的位置j+1,
   1.若p[k]==p[j] next[j+1]=next[j]+1
   2.若p[k]≠p[j] 记h=next[k];如果p[h]==p[j],则next[j+1]=h+1,否则重复此过程
*/

void get_next(const char* p,int next[])
{
    int nlen = (int)strlen(p);
    next[0] = -1;
    int k = -1;///k就是next[j-1]
    int j = 0;
    while(j < nlen-1)
    {
        if(k ==-1 || p[j]==p[k])//k就是next[j-1]  p[k]表示前缀　　p[j]表示后缀

        {
            ++j;
            next[j] = k++;
        }
        else///p[j]　p[k]匹配失败　递归求前缀p[next[k]]
        {
            k = next[k];
        }
    }
}

///变种的ＫＭＰ
void get_next2(const char* p,int next[])
{
    int nlen = (int)strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while(j < nlen-1)
    {
        if(k ==-1 || p[j]==p[k])//k就是next[j-1]  p[k]表示前缀　　p[j]表示后缀

        {
            ++j;
            ++k;
            if(p[j]==p[k])
            {
                next[j] = next[k];///变种之后　表示p[j] p[k]都匹配失败　直接让next[j]变成next[k]
            }
            else
            {
                next[j] = k;
            }

        }
        else///p[j]　p[k]匹配失败　递归求前缀p[next[k]]
        {
            k = next[k];
        }
    }
}

int kmp(int n)
{
    int ans = -1;
    int i = 0;
    int j = 0;
    int pattern_len = strlen(g_pattern);
    while(i < n)
    {
        if(j==-1|| g_s[i] == g_pattern[j])
        {
            ++i;++j;
        }
        else
        {
            j = g_next[j];
        }
        if(j == pattern_len)
        {
            ans = i-pattern_len;
            break;
        }
    }
    return ans;
}

/*分析：
经典的ＫＭＰ：
最好情况:当模式串的首字符和其他字符都不相等时,模式串不存在相等的k前缀和k后缀,next数组全为-1　一旦匹配失效,模式串直接跳过已经比较的字符。比较次数为N
最差情况:当模式串的首字符和其他字符全都相等时,模式串存在最长的k前缀和k后缀,next数组呈现递增样式:-1,0,1,2...

变种kmp:
最好情况：当模式串的首字符和其他字符全都相等时，next数组全为-1

*/

/*案例：给定一个长度为n的字符串S,如果存在一个字符串T,重复若干次T能够得到S,那么,S叫做周期串,T叫做S的一个周期。 如:字符串abababab是周期串,abab、ab都
是它的周期,其中,ab是它的最小周期。 设计一个算法,计算S的最小周期。如果S不存在周期,返回空串。



使用next,线性时间解决问题



计算S的next数组;记k=next[len],p=len-k;　若len%p==0,则p为最小周期长度,前p个字符就是最小周期
*/











