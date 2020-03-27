#include <stdio.h>
#include <string.h>

int str_replace(char *src, char *find, char *replace)
{
    int i, j, len1, len2, len3, move;
    if (src == NULL || find == NULL || replace == NULL) {
        return -1;
    }
    len1 = strlen(src);
    len2 = strlen(find);
    len3 = strlen(replace);

    for (i = 0; i <= len1 - len2; i++) {
        if (src[i] == find[0]) {
            for (j = 1; j < len2; j++) {
                if (src[i + j] != find[j])
                    break;
            }
            if (j == len2) {
                move = strlen(replace) - strlen(find);
                if (move > 0) {
                    for (j = len1; j >= i + len2; j--) {
                        src[j + move] = src[j];
                    }
                    for (j = 0; j < len3; j++) {
                        src[i + j] = replace[j];
                    }
                } else {
                    move = strlen(find) - strlen(replace);
                    for (j = i + len2; j <= len1; j++) {
                        src[j - move] = src[j];
                    }
                    for (j = 0; j < len3; j++) {
                        src[i + j] = replace[j];
                    }
                }
            }

        }
    }
    return 0;
}

int main(void)
{
    char buf[1024] = {0};
    char find[100] = {0};
    char replace[100] = {0};

    scanf("%s", find);
    scanf("%s", replace);
    while(scanf("%s", buf) != EOF) {
        str_replace(buf, find, replace);
        printf("%s\n", buf);
    }

    return 0;
}