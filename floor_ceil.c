///找浮点数s最接近的整数
///ceil 向上取整  floor 向下取整
#include<stdio.h>
#include<math.h>
double round_nearest(double x)
{
    return x<0.0 ? ceil(x-0.5) : floor(x+0.5);
}

int main()
{
    double s;
    scanf("%lf",&s);
    s = round_nearest(s);
    printf("%lf",s);
    return 0;
}
