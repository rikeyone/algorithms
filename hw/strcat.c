#include <stdio.h>

char *strcat(char *dest, char *src)
{
    char *p, *q;
    p = dest;
    q = src;

    while(*p != '\0') {
        p++;
    }
    while(*q != '\0') {
        *p++ = *q++;
    }
    *p = '\0';
    return p;
}

int main(void)
{
    char src[1024] = {0};
    char dest[1024] = {0};

    scanf("%s", src);
    scanf("%s", dest);

    strcat(dest, src);
    printf("%s\n", dest);
    return 0;
}