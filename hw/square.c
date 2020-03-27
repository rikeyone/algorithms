/*
求一个二维数组中为全部为1的最大的正方形面积

0 0 0 1
0 1 1 1
0 1 1 1


if buffer[i][j] == 1
dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1
else
dp[i][j] = 0

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define min(x,y) ((x < y) ? (x) : (y))
#define max(x,y) ((x > y) ? (x) : (y))

int main(void)
{
    int row, colume, i, j, side;

    while(scanf("%d", &row) != EOF) {
        char buffer[row][1024];
        memset(buffer, 0, sizeof(buffer));
        for (i = 0; i < row; i++) {
            scanf("%s", buffer[i]);
        }
        colume = strlen(buffer[0]);
        int dp[row][colume];
        memset(dp, 0, sizeof(dp));
        side = 0;
        //dp[0][x]
        for (j = 0; j < colume; j++) {
            if (buffer[0][j] == '1') {
                dp[0][j] = 1;
                side = max(side, dp[0][j]);
            }
        }
        //dp[x][0]
        for (i = 0; i < row; i++) {
            if (buffer[i][0] == '1') {
                dp[i][0] = 1;
                side = max(side, dp[i][0]);
            }
        }
        //dp[x][y] x > 0 and y >0
        for (i = 1; i < row; i++) {
            for (j = 1; j < colume; j++) {
                if (buffer[i][j] == '1') {
                    dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                    dp[i][j] = dp[i][j] + 1;
                    side = max(side, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        printf("max side:%d\n", side);
        printf("max area:%d\n", side * side);

    }
}