//查找一个字符串中无重复最长子串的长度

#include <stdio.h>

#define max(a,b) ((a) > (b)) ? (a) : (b)
int length_of_substring(char *str)
{
    int start = 0, end = 0;
    int i, len, result, temp;

    len = strlen(str);
    result = 1;
    for (end = 0; end < len; end++) {
        temp = end - start + 1;
        for (i = start; i < end; i++) {
            if (str[i] == str[end]) {
                if (start < end)
                    start = i + 1;
                temp = end - start + 1;
            }
        }
        result = max(result, temp);
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