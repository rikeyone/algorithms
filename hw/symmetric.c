#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char buffer[1024];

int main(void)
{
    int i, len, half, symmetric;
    char output[1024];

    while(scanf("%s", buffer) != EOF) {
        len = strlen(buffer);
        if (len % 2) {
            printf("false\n");
            continue;
        }
        half = len / 2;
        symmetric = 1;
        memset(output, 0, 1024);
        for (i = 0; i < half; i++) {
            if (buffer[i * 2] != buffer[i * 2 + 1]) {
                symmetric = 0;
                break;
            }
            if (buffer[i] != buffer[len - 1 - i]) {
                symmetric = 0;
                break;
            }
            output[i] = buffer[i * 2];
        }

        if (symmetric) {
            printf("%s\n", output);
        } else {
            printf("false\n");
        }
    }
    return 0;
}