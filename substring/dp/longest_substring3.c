//查找字符串中的最长子串的长度，要求子串中所有字符按照升序列排序（相等也符合要求）

/*
动态规划算法来求解此问题，使用dp[i]来表示长度为i的字符串中符合要求的最长子串，那么dp[i -1]就表示前面的i-1个字符表示的字符串中
的符合要求的最长子串的长度。状态转移公式如下：

dp[i] = dp[i - 1] + 1;

那么关键的子问题是：什么时候才能满足这个条件，使用这个公式进行计算呢？
问题可以这么来解释，当增加到第i个字符，需要从第i个字符开始算起，往前推算dp[i - 1] + 1个字符位置，如果在这个区间之内，所有的字符
都是按照升序排序，那么说明这个子串是符合要求的，可以进行如上公式来操作。

*/

#include <stdio.h>
#include <string.h>


int should_increase_dp(char *buf, int *dp, int index)
{
    int i;
    int len = dp[index - 1] + 1;

    for(i = index; i > index - len; i--) {
        if (buf[i] < buf[i - 1])
            return 0;
    }
    return 1;
}

int length_of_substring(char *buf)
{
    int dp[1024] = {0};
    int i, len, result;

    len = strlen(buf);
    dp[0] = 1;
    for(i = 1; i < len; i++) {
        if (should_increase_dp(buf, dp, i))
            dp[i] = dp[i - 1] + 1;
        else
            dp[i] = dp[i - 1];
    }
    return dp[len - 1];
}

int main(void)
{
    char buf[1024];

    while(scanf("%s", buf) != EOF) {
        printf("%d\n", length_of_substring(buf));
    }
    return 0;
}