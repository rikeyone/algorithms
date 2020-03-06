//查找字符串中的最长连续子串的长度
/*
动态规划算法来求解此问题，使用dp[i]来表示长度为i的字符串中符合要求的最长子串，那么dp[i -1]就表示前面的i-1个字符表示的字符串中
的符合要求的最长子串的长度。状态转移公式如下：

dp[i] = dp[i - 1] + 1;

那么关键的子问题是：什么时候才能满足这个条件，使用这个公式进行计算呢？
问题可以这么来解释，当增加到第i个字符，需要从第i个字符开始算起，向前计算连续字符串长度，如果大于dp[i-1]，那么说明dp[i] = dp[i-1] + 1
否则dp[i] = dp[i - 1]

*/

#include <stdio.h>
#include <string.h>

static char buf[1024];
static int dp[1024];

int should_increase_dp(char c, int index)
{
    int i, len = 0;

    for (i = index; i >= 0; i--) {
        if (buf[i] == c)
            len++;
        else
            break;
    }
    if (len > dp[index - 1])
        return 1;
    else
        return 0;
}

int length_of_substring(char *buf)
{
    int i, j, len;

    len = strlen(buf);
    dp[0] = 1;
    for (i = 1; i < len; i++) {
        if (should_increase_dp(buf[i], i)) {
            dp[i] = dp[i - 1] + 1;
        } else {
            dp[i] = dp[i - 1];
        }
    }
    return dp[len - 1];
}

int main(void)
{
    while(scanf("%s", buf) != EOF) {
        printf("%d\n", length_of_substring(buf));
    }

    return 0;

}