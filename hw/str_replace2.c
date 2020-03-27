#include <stdio.h>
#include <string.h>

int str_replace(char *src, char *find, char *replace)
{
    char temp[1024] = {0};
    int i, j, len1, len2, len3, count = 0;

    if (src == NULL || find == NULL || replace == NULL) {
        return -1;
    }

    len1 = strlen(src);
    len2 = strlen(find);
    len3 = strlen(replace);

    if (len1 < len2)
        return 0;

    for (i = 0; i <= len1 - len2; i++) {
        if (src[i] == find[0]) {
            for (j = 0; j < len2; j++) {
                if (src[i + j] != find[j]) {
                    break;
                }
            }
            //match string find
            if (j == len2) {
                strcpy(temp + count, replace);
                count += len3;
                i = i + len2 - 1;
            } else {
                temp[count++] = src[i];
            }
        } else {
            temp[count++] = src[i];
        }
    }
    strcpy(src, temp);
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