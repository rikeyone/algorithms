/*
总共有m个商品（最大不超过60）和总数为N(最大不超过32000)的钱数，每个商品有各自的价格v（10的倍数）和重要度w，求如何选择才能让所有被选物品的 v*w 总和最大，求这个最大值。
*/
#include <stdio.h>

//3个考虑分量：价格，重要度，（价格*重要度）
//两个限制参量：商品总数量，总钱数
//使用dp[i][j]来表示在i个数量的商品中找出总钱数为j的最佳策略，此时的所有 v*w 的总和。

#define max(a,b) (a > b ? a : b)

int main(void)
{
    int v[60] = {0};
    int w[60] = {0};
    int vw[60] = {0};
    int dp[60][32000/10] = {0};
    int i, j;
    int m, N;

    scanf("%d %d", &m, &N);

    for(i = 1; i <= m; i++) {
        for(j = 1; j <= N; j++) {
            if(j < v[i]) { //总的钱数小于第i个商品的价格，此时应该和i - 1个商品，总钱为j时的最大值是一样的
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - v[i]] + vw[i]);
            }
        }
    }
    printf("max dp:%d\n", dp[m][N]);
    return 0;
}