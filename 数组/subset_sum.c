/*
已知数组A[0...N-1],给定某数值sum,找出数组中的若干个数,使得这些数的和为sum。

*/
//1.直接递归法(枚举)
//2.分支限界
//3.存在负数的处理办法

///直接递归

int a[] ={1,2,3,4,5};
int size = sizeof(a)/sizeof(int);
int sum = 10;//sum 为子集和

void ennumber(bool* x,int i,int has)///x[]为最终解　x[i]可以表示是否加入当前子集和
{
    if(i>size)
        return;
    if(has+a[i] == sum)///递归出口
    {
        x[i] = true;
        print(x);
        x[i] = false;
    }
    x[i] = true;///分开考虑
    ennumber(x,i+1,has+a[i]);
    x[i] = false;
    ennumber(x,i+1,has);

}
int main(int argc,char* argv[])
{
    bool* x = new bool[size];
    memset(x,0,0);
    ennumber(x,0,0);
    delete[] x;
    return 0;
}


///分支限界　　数组A[0...N-1]的元素都大于0
/*前提:数组A[0...N-1]的元素都大于0,
考察向量x[0...N-1],假定已经确定了前i个值,现在要判定第i+1个值x[i]为0还是1


假定由x[0...i-1]确定的A[0...i-1]的和为has
A[i,i+1,...N-1]的和为residue 记做r

分支：　１。has+a[i]≤sum并且has+r≥sum:x[i]可以为1
　　　　２。has+(r-a[i])>= sum:x[i]可以为0
*/
void finnumber(bool* x,int i,int has,int residue)
{
    if(i>=size)
        return;
    if(has+a[i] == sum)
    {
        x[i] = true;
        print(x);
        x[i] = false;
    }
    else if((has+residue>=sum)&&(has+a[i]<=sum))///可以取a[i]
    {
        x[i] = true;
        finnumber(x,i+1,has+a[i],residue-a[i]);
    }
    if(has+residue-a[i]>=sum)//可以取０
    {
        x[i] = false;
        finnumber(x,i+1,has,residue-a[i]);
    }

}

///如何对负数进行分支限界?
/* 可对整个数组A[0...N-1]正负排序,使得负数都在前面,正数都在后面,使用剩余正数的和作为分支限界的约束:
1.如果A[i]为负数:如果全部正数都算上还不够,就不能选A[i];
2.如果递归进入了正数范围,按照数组是全正数的情况正常处理
*/





















