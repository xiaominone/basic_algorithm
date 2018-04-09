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
    int k = -1;
    int j = 0;
    while(j < nlen-1)
    {
        if(k ==-1 || p[j]==p[k])
        {
            ++k;
            ++j;
            next[j] = k;
        }
        else
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














