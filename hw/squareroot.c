#include <math.h>
#include <stdio.h>
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
