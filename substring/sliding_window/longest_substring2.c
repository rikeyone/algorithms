//查找子串的最大长度，要求，子串中所有的字符个数不超过k个

#include <stdio.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))
int should_start_move(char *str, int start, int end, int k)
{
    int mask[128] = {0};
    int i, c, sum = 0;
    for (i = start; i <= end; i++) {
        c = str[i];
        mask[c] = 1;
    }
    for (i = 0; i < 128; i++) {
        sum += mask[i];
    }
    if (sum > k) {
        return 1;
    } else {
        return 0;
    }
}

int length_of_substring(char *str, int k)
{
    int start, end, i, result, temp;
    int len;
    int buf[100];

    len = strlen(str);
    start = 0;
    result = 0;
    for (end = 0; end < len; end++) {
        temp = end - start + 1;
        for (i = start; i < end; i++) {
            if (should_start_move(str, start, end, k)) {
                start = i + 1;
                temp = end - start + 1;
            }
        }

        snprintf(buf, temp + 1, "%s", str + start);
        printf("%s\n", buf);
        printf("temp:%d start:%d, end:%d\n", temp, start, end);

        result = max(result, temp);

    }
    return result;
}

int main(void)
{
    char buf[1024];
    int k;

    scanf("%d", &k);
    while(scanf("%s", buf) != EOF) {
        printf("%d\n", length_of_substring(buf, k));
    }

    return 0;
}