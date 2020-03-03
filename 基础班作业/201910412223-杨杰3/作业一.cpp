#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
int main()
{
    int i = 1;
    double x, x2, result = 1, tmp1 = 1, tmp2 = 1, tmp3;

    printf("输入PI的时间:");
    scanf_s("%lf", &x);
    x2 = PI * x * x * PI;

    do
    {
        tmp1 *= x2;
        tmp2 *= ((2 * i - 1) * 2 * i);
        tmp3 = (tmp1 / tmp2);
        if (i % 2 == 0)
            result += tmp3;
        else
            result -= tmp3;
        i++;
    } while (tmp3 > 0.0000001 || tmp3 < -0.0000001);

    printf("result=%lf\n", result);

    return 0;
}