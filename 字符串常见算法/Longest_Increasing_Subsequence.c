/*
给定一个长度为N的数组,找出一个最长的单调递增子序列。
例如:给定数组 {5, 6, 7, 1, 2, 8},则其最长的单调递增子序列为{5,6,7,8},长度为4。

*/

///解析1：将数组进行排序 然后使用最长公共子序列的动态规划


/*动态规划
解析2：以a[i] 结尾的最长递增子序列记做Li ,其长度记为b[i]

b[i]={max(b[j])+1, 0≤=j<i且a[j]≤a[i]}

计算b[i]:遍历在i之前的所有位置j,找出满足条件a[j]≤a[i] 的最大的b[j]+1;遍历所有的b[i],找出最大值即为最大递增子序列的长度。
*/


int lis(cons int* p,int length,int* pre,int nindex)
{
    int* longest = new int[length];
    int i,j;

    for(i = 0;i<length; i++)
    {
        longest[i] = 1;
        //pre[i] = -1;///以i位置的最长字符串的起点
    }

    int longest_length = 1;///最长字符串长度
    int nindex = 0;///最长字符串的结尾

    for(i=1;i<length;i++)
    {
        for(j=0;j<i;j++)
        {
            if(p[j]<p[i])
                if(longest[i]<longest[j]+1)
                {
                    longest[i] = longest[j]+1;
                    //pre[i] = j;///最长字符串的开始位置
                }


        }
        if(longest_length<longest[i])
        {
            longest_length = longest[i];
            nindex = i;///最长字符串结尾
        }
    }




}
