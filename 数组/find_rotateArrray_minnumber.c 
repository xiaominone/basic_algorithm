/*
假定一个排序数组以某个未知元素为支点做了旋转,如:原数组0 1 2 4 5 6 7旋转后得到4 5 6 7 0 1 2。请找出旋转后数组的最小值。假定数组中没有重复数字

*/

///旋转之后的数组实际上可以划分成两个有序的子数组:前面子数组的大小都大于后面子数组中的元素
///最小的元素就是两个子数组的分界线。


///二分查找确定是普通升序还是循环升序数组

/*
用索引left,right分别指向首尾元素,元素不重复。若子数组是普通升序数组,则A[left]<A[right]
若子数组是循环升序数组,前半段子数组的元素全都大于后半段子数组中的元素:A[left]>A[right]
计算中间位置mid = (low+high)/2 显然,A[low...mid]与A[mid+1...high]必有一个是循环升序数组,一个是普通升序数组。

1 若:A[mid]>A[high],说明子数组A[mid+1,mid+2,...high]循环升序;更新low=mid+1;
2 若:A[mid]<A[high] ,说明子数组A[mid+1,mid+2,...high]普通升序;更新:high=mid

*/

int findmin(int* num,int size)
{
    int low = 0;
    int high = size-1;
    int mid;
    while(low<high)
    {
        mid = (high+low)/2;
        if(num[mid]<num[high])
            high = mid;
        else if(num[mid]>num[high])
            low = mid +1;

    }
    return num[low];
}







