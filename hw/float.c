#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static char buffer[1024];
static char number[1024];

int main(void)
{
    int i, j, len, start, end, max, temp;

    while(scanf("%s", buffer) != EOF) {
        max = 0;
        len = strlen(buffer);
        memset(number, 0, 1024);
        start = 0;
        end = 0;
        for (start = 0; start < len; start++) {
            if (buffer[start] >= '0' && buffer[start] <= '9') {
                for (end = start + 1; end < len; end++) {
                    if ((buffer[end] >= '0' && buffer[end] <= '9')) {
                        continue;
                    } else if (buffer[end - 1] == '.' && buffer[end] == '.') {
                        end--;
                        break;
                    } else if (buffer[end - 1] != '.' && buffer[end] == '.') {
                        continue;
                    } else {
                        end--;
                        break;
                    }
                }
                if (end == len) {
                    end--;
                }
                if (buffer[end] == '.') {
                    end--;
                }
                temp = end - start + 1;
                if (temp >= max) {
                    strncpy(number, &buffer[start], temp);
                    max = temp;
                }
                start = end;
            }
        }
        printf("%s\n", number);
    }
}