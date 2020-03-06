//求给定字符串中的最长子串的长度，要求子串中所有字符个数不超过k

/*
使用动态规划法解决此问题，首先确定状态转移公式：
我们使用dp[i]来表示是长度为i的字符串中符合条件的子串最大长度，那么dp[i - 1]就表示前i - 1个
长度中符合条件的子串最大长度。
dp[i] = dp[i - 1] + 1;

接下来一个关键点就是什么时候决定运行此条件转移公式，要求子串中所有字符个数不超过k，也就是当
增加到i个字符时，从i个字符开始算起，往前计算dp[i - 1] + 1个字符，如果这个范围内的所有字符
个数不超过k，那么此时说明当轮训到第i个字节时，有比dp[i - 1]更长的子串了，条件满足，所以可以
按照上述公式计算，否则说明dp[i] = dp[i - 1]。


*/

#include <stdio.h>
#include <string.h>


int should_increase_dp(char *buf, int *dp, int index, int k)
{
    int i, len, sum = 0;
    int mask[256] = {0};
    char c;

    len = dp[index - 1] + 1;

    for (i = 0; i < len; i++) {
        c = buf[index - i];
        mask[c] = 1;
    }
    for (i = 0; i < 256; i++) {
        sum += mask[i];
    }

    if (sum > k)
        return 0;
    else
        return 1;
}

int length_of_substring(char *buf, int k)
{
    int i, result;
    int dp[1024] = {0};
    dp[0] = 0;
    for(i = 1; i < strlen(buf); i++) {
        if (should_increase_dp(buf, dp, i, k))
            dp[i] = dp[i - 1] + 1;
        else
            dp[i] = dp[i - 1];
    }
    return dp[strlen(buf) - 1];

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