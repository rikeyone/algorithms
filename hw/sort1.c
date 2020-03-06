#include <stdio.h>

int main(void)
{
    int buf[10];
    int i, j, temp;
    for(i = 0; i < 10; i++) {
        scanf("%d", &buf[i]);
    }
    for (i = 0; i < 9; i++) {
        for(j = i + 1; j < 10; j++) {
            if (buf[i] > buf[j]) {
                temp = buf[i];
                buf[i] = buf[j];
                buf[j] = temp;
            }
        }
    }
    for (i = 0; i < 10; i++) {
        printf("%d ", buf[i]);
    }
    return 0;
}