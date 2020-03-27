#include <stdio.h>
#include <string.h>

static char str[] = "Computer Science";

int main(void)
{
    int i = 0, j = 0, len = 0;
    char *p = str;

    len = strlen(str);
    for (i = 0; i < len; i++) {
        if (*(p + i) == ' ') {
            for (j = i; j <= len; j++) {
                *(p + j) = *(p + j + 1);
            }
        }
    }
    for(i = 0; i < len; i++) {
        if ((i) % 2 == 0) {
            printf("%c", *(p + i));
        }
    }
    printf("\n");
    return 0;
}