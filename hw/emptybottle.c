#include <stdio.h>

int main(void)
{
    int m, result, mod;
    int sum = 0;

    while(scanf("%d", &m) != EOF) {
        result = m;
        mod = 0;
        sum = 0;
        while(result >= 3) {
            mod = result % 3;
            result = result / 3;
            sum += result;
            result = result + mod;
        }
        if (result == 2) {
            sum++;
        }
        printf("%d\n", sum);
    }
    return 0;

}