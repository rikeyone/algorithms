#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *word[1000];

int main(void)
{
    char buf[2048];
    int len = 0, i, count = 0;
    char *s, *start, *end;
    while(fgets(buf, 2048, stdin)) {
        len = strlen(buf) - 1;
        buf[len] = '\0';
        s = buf;
        start = buf;
        while(*s++ == ' ') {
            start = s;
        }
        s = buf + len - 1;
        while(*s == ' ') {
            *s-- = '\0';
        }
        len = strlen(start);
        word[count++] = start;
        for (i = 0; i < len; i++) {
            if (start[i] == ' ') {
                start[i] = '\0';
                s = start + i + 1;
                word[count++] = s;
            }
        }
        for (i = count - 1; i >= 0; i--) {
            printf("%s", word[i]);
            if (i != 0)
                printf(" ");
            else
                printf("\n");

        }
    }
    return 0;
}