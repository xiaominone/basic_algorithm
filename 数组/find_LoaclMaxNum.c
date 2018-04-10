/*
二分查找　也用局部最值的查询
若子数组Array[from,...,to]满足Array[from]>Array[from-1]　　Array[to]>Array[to+1]称该子数组为“高原数组”。
若高原数组长度为1,则该高原数组的元素为局部最大值
*/
int localmaxnum(const char* A,int size)
{
    int left =0;
    int right = size-1;
    int mid;
    while(left<right)
    {
        mid =(left+right);
        cout<<mid<<endl;
        if(A[mid]>A[mid+1])
        {
            right = mid;
        }
        else
        {
            left = mid+1;
        }


    }
    return A[left];
}
