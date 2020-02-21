//冒泡法排序

#include <stdio.h>

int main(void)
{
    int buf[10];
    int i, j, temp;

    for (i = 0; i < 10; i++) {
        scanf("%d", &buf[i]);
    }
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 10 - 1 - i; j++) {
            if (buf[j] > buf[j+1]) {
                temp = buf[j];
                buf[j] = buf[j+1];
                buf[j+1] = temp;
            }
        }
    }
    for (i = 0; i < 10; i++) {
        printf("%d ", buf[i]);
    }
    return 0;
}
