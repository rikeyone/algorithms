//求一定范围内的素数

#include <stdio.h>


int main()
{
    int i, j, match;
    for (i = 2; i <= 100; i++) {
        match = 1;
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                match = 0;
                break;
            }
        }
        if (match) {
            printf("%d\n", i);
        }
    }
    return 0;
}

