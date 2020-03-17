#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/*
front: 16 - 1
back: 2 - 15
front: 14 - 3
back: 4 - 13
front:12 - 5
back:6 - 11
front:10 - 7
back:8 - 9

*/

static int buf[1024] = {0};

int main(void)
{
    int paper, i, sum, big_paper;

    while(scanf("%d", &paper) != EOF) {
        for (i = 0; i < paper; i++) {
            buf[i] = i + 1;
        }
        if ((paper % 4) != 0) {
            sum = paper + (4 - (paper % 4));
        } else {
            sum = paper;
        }
        big_paper = sum / 4;
        for (i = 0; i < big_paper; i++) {
            printf("front:");
            if (buf[sum - 1 - i * 2])
                printf("%d - ", buf[sum - 1 - i * 2]);
            else
                printf("None - ");

            if (buf[i * 2])
                printf("%d", buf[i * 2]);
            else
                printf("None");
            printf("\n");
            printf("back:");
            if (buf[i * 2 + 1])
                printf("%d - ", buf[i * 2 + 1]);
            else
                printf("None - ");

            if (buf[sum - 1 - i * 2 - 1])
                printf("%d", buf[sum - 1 - i * 2 - 1]);
            else
                printf("None");
            printf("\n");
        }
        memset(buf, 0, sizeof(int) * 1024);
    }
    return 0;
}