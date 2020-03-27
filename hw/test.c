#include <stdio.h>

int main(void)
{
    char buf[1024] = {0};
    char *p = NULL;
    int len = 0;

    while(scanf("%s", buf) != EOF) {
        p = buf;
        while(*p++ != '\0');
        len = p - buf - 1;
        printf("%d\n", len);
    }

    return 0;

}