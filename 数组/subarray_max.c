/*
给定一个数组A[0,...,n-1],求A的连续子数组,使得该子数组的和最大

*/

///基本解法
1.for i = 1,2,3,4,..n 求出sum[i]  (表示a[0]+a[1]+...+a[i])
2.for j = 1,2,3..j;求出以a[j]结尾的最小sum 即m;
3.sum[i]-m 表示以a[i]结尾的为最大值　不断更新


///动态规划
/*记S[i]为以A[i]结尾的数组中和最大的子数组则:S[i+1] = max(S[i]+A[i+1], A[i+1])
S[0]=A[0]
遍历i: 0≤i ≤n-1
*/
int max_subarry(const char* a,int size)
{
    if(!a||size<0)
        return 0;
    int sum = a[0];///当前以a[0]结尾的子串的和
    int result = sum;
    for(int i = 1;i<size;i++)
    {
        sum = max(sum+a[i],a[i]);
        if(sum>reuslt)
            result = sum;
    }
    return result;
}

///输出最大子数组以及和
int max_subarry(const char* a,int size)
{
    int from, to,fromnew;
    if(!a||size<0)
    {
        from = to = -1;
        return 0;
    }
    from = to = 0;
    int sum = a[0];///当前以a[0]结尾的子串的和
    int result = sum;
    for(int i = 1;i<size;i++)
    {
        if(sum>0)
        {
            sum+=a[i];
        }
        else
        {
            sum = a[i];
            fromnew = i;///新的数组起点
        }
        if(sum>reuslt)
        {
            result = sum;
            from = fromnew;
            to = i;
        }

    }
    return result;//from ,to
}

























