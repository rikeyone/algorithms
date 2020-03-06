//求字符串子串的最大长度，要求子串中的字符是按照升序排列的（字符相等也符合要求）。

#include <stdio.h>
#include <string.h>

int is_substring_increase(char *buf, int start, int end)
{
    int i;
    for (i = start; i < end; i++) {
        if (buf[i] > buf[i + 1])
            return 0;
    }
    return 1;
}

int length_of_substring(char *buf)
{
    int start, end, len;
    int i, result, temp;
    int dbuf[100] = {0};

    len = strlen(buf);
    start = 0;
    end = 0;
    result = end - start + 1;

    for (end = 0; end < len; end++) {
        temp = end - start + 1;
        for (i = start; i < end; i++){
            if (!is_substring_increase(buf, start, end)) {
                start = i + 1;
                temp = end - start + 1;
            }
            snprintf(dbuf, temp + 1, "%s", buf + start);
            printf("%s\n", dbuf);
        }
        result = temp > result ? temp : result;
    }
    return result;
}


int main(void)
{
    char buf[1024];

    while(scanf("%s", buf) != EOF) {
        printf("%d\n", length_of_substring(buf));
    }

    return 0;
}