/*
求对于长度为N的数组A,求连续子数组的和最接近0的值

*/

///申请比A长1的空间sum[0...,N], sum[i]是A的前i-1项和 求出sum
///对sum排序,然后计算sum相邻元素的差的绝对值,最小值即为所求  即在A中任意取两个前缀子数组的和求差的最小值


int minsubarry(const char* a;int size)
{
    int *sum = new int[size+1];
    sum[0] = 0;
    int i;
    for(i = 0;i<size;i++)
    {
        sum[i+1] = sum[i]+a[i];///sum[i]表示前ｉ－１项和
    }
    sort(sum,sum+size+1);
    int difference = abs(sum[1]-sum[0]);
    int result = difference;
    for(i = 1;i<size;i++)
    {
        difference = abs(sum[i+1]-sum[i]);
        result = min(difference,result);
    }
    return result;
}
