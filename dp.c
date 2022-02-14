/*
 *  座位在X.Y处，不能接触N
 *  查找路径选择个数
 *
 *  典型的动态规划算法
 *
 *
 *
 *
 * */

#include <stdio.h>

long long dp[100][100];

int main(void)
{
	int x, y, n, i, j, X, Y;
	scanf("%d %d %d", &X, &Y, &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		dp[x][y] = -1;
	}
	for (i = 0; i <= X; i++) {
		for (j = 0; j <= Y; j++) {
			if (dp[i][j] == -1) {
				dp[i][j] = 0;
				continue;
			}
			if (i == 0 && j == 0) {
				dp[i][j] = 1;
				continue;
			}
			if (i == 0 && j != 0) {
				dp[0][j] = dp[0][j - 1];
				continue;
			}
			if (i != 0 && j == 0) {
				dp[i][0] = dp[i - 1][0];
				continue;
			}
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	printf("%ld\n", dp[X][Y]);
}
