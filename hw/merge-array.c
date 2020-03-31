#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    int num1, num2, i, j, count, match;

    while(1) {
        if (scanf("%d", &num1) == EOF) {
            break;
        }
        int a1[num1];
        for (i = 0; i < num1; i++) {
            if (scanf("%d", &a1[i]) == EOF) {
                return 0;
            }
        }
        if (scanf("%d", &num2) == EOF) {
            break;
        }
        int a2[num2];
        for (i = 0; i < num2; i++) {
            if (scanf("%d", &a2[i]) == EOF) {
                return 0;
            }
        }
        int sum[num1 + num2];
        int merged[num1 + num2];
        memcpy(sum, a1, sizeof(a1));
        memcpy(sum + sizeof(a1), a2, sizeof(a2));
        count = 0;
        for (i = 0; i < sizeof(sum); i++) {
            match = 0;
            for (j = 0; j < count; j++) {
                if (merged[j] == sum[i]) {
                    match = 1;
                    break;
                }
            }
            if (!match) {
                merged[count++] = sum[i];
            }
        }

        for (i = 0; i < count; i++) {
            printf("%d ", merged[i]);
        }

    }
    return 0;
}