#include <stdio.h>

//x^3 = a
//f(x) = x^3 -a
//X(k+1) = X(k) - f(x)/f(x)'
#define ABS(x) (((x) > 0) ? (x) : (0 - x))
double cuberoot(double value)
{
    double x = 1.0;
    do {
        x = (2 * x + (value / (x * x))) / 3;
    } while(ABS(x*x*x - value) > 0.1E-6);
    return x;
}

int main(void)
{
    double value;

    while(scanf("%lf", &value) != EOF) {
        printf("%.1lf", cuberoot(value));
    }
    return 0;
}
