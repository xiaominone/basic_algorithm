/*
给定字符串S[0...N-1],设计算法,枚举S的全排列

*/

/*
1.当字符串中没有重复字符，递归

*/
void permutation(int* a,int size, int n)
{
    if(n==size-1)
    {
        print(a,size);
        return;
    }
    for(int i=n;i<size;i++)///将位置n的数字与(n+1,size)区间内的数字交换
    {
        swap(a[i],a[n]);
        permutation(a,size,n+1);
        swap(a[i],a[n]);

    }

}
/*
2.当字符串中有重复字符,每个字符分别与它后面非重复出现的字符交换
要求：第i个字符与第j个字符交换时,要求[i,j)中没有与第j个字符相等的数。

*/
void permutation(int* a,int size,int n)
{
    if(n==size-1)
    {
        print(a,size);
        return;
    }
    for(int i=n;i<size;i++)
    {
        if(!isrepat(a,n,i))/// 第n个字符与第i个字符交换时,要求[n,i)中没有与第i个字符相等的数。
            continue;
        swap(a[i],a[n]);
        permutation(a,size,n+1);
        swap(a[i],a[n]);
    }

}
bool isrepat(int* a,int n,int i)
{
    while(n<i)
    {
        if(a[n]==a[i])
            return false;
        n++;
    }
    return true;
}

/*
全排列的非递归算法  字典序
步骤:后找、小大、交换、翻转——
1.后找:字符串中最后一个可以升序的位置i
2.查找(小大):S[i+1...N-1]中比Ai大的最小值Sj;
3.交换:Si,Sj;
4.翻转:S[i+1...N-1]  注：交换操作后,S[i+1...N-1]一定是降序的

举例：21543
1逐位考察哪个能增大
   一个数右面有比它大的数存在,它就能增大，那么最后一个能增大的数是——x = 1
2应该增大到多少?
   增大到它右面比它大的最小的数——y = 3
3应该变为23xxx
4显然,xxx应由小到大排:145
5得到23145

*/
///找到最后一个可以升序字符i，进行交换后，i后面的字符一定是降序的 直接翻转就可以  不用从小到大排序
void reverse(int* from,int* to)
{
    int t;
    while(from<to)
    {
        t = *from;
        *from = *to;
        *to = t;
        from++;
        to--;
    }
}

bool get_nextpermutation(int* a,int size)
{
    ///从后向前找 找到最后一个可以升序的i
    int i = size-2;
    while((i>=0)&&a[i]>=a[i+1])///只要i位置后面的任一数都比a[i]大即可
        i--;
    if(i<0)
        return false;

    ///查找位置i后面比a[i]大的最小数 i后面的元素一定是降序
    int j = size-1;
    while(a[j]<=a[i])
        j--;///降序，找到第一个大于a[i]的就行

    ///交换
    swap(a[j],a[i]);

    ///翻转 （i后元素 降序变为升序）
    reverse(a+i+1,a+size-1);
    return true;

}

