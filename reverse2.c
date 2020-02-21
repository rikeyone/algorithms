#include <stdio.h>

int main(void)
{
    int buf[1024];
    int reverse[1024];
    int count = 0, i;
    while(scanf("%d", &buf[count]) != EOF) {
        count++;
        if (count >= 1024) {
            printf("buffer full\n");
            break;
        }
    }
    for (i = 0; i < count; i++) {
        reverse[i] = buf[count - 1 - i];
    }
    for (i = 0; i < count; i++) {
        printf("%d ", reverse[i]);

    }
    printf("\n");
    return 0;
}