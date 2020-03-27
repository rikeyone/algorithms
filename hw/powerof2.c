#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num = 0;

    while(scanf("%d", &num) != EOF) {
        if (num == 0) {
            printf("%d is not a power of 2\n", num);
            continue;
        }
        if ((num & (num - 1)) == 0) {
            printf("%d is a power of 2\n", num);
        } else {
            printf("%d is not a power of 2\n", num);
        }
    }
    return 0;
}