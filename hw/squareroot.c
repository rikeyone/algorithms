#include <math.h>
#include <stdio.h>
/*
 * 某个点x0处的导数，就相当于是x0处切线的斜率k
 * delta(y) = delta(x) * k
 * 
 * y1 - y0 = (x1 - x0) * k
 * 0 - f(x0) = (x1 - x0) * k
 * -f(x0) / k = x1 - x0
 * x1 = x0 - f(x0)/f(x0)'
 *
 * f(x) = x^2 - a
 * x1 = x0 - f(x0)/f(x0)'
 * x1 = x0 - ((x0^2 -a)/(2*x0)) = (x0 + a / x0) / 2
 *
 * */
int main(void)
{
    float a, x1, check;
    scanf("%f", &a);

    x1 = 1;
    do {
        x1 = (x1 + a / x1) / 2;
        check = x1 * x1 - a;
    } while((check ? check : 0 - check) > 1.0E-5); //精确到小数点后5位
    printf("%f\n", x1);
    return 0;
}
