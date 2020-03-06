#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "math.h"
int OddArray[101];
int EvenArray[101];
int OddNum = 0;
int EvenNum = 0;
int Result[101];
int visited[101];
int ansNum = 0;
int Odd2Even[101][101]={0};

int isSuShuPairs(int tmpX, int tmpY)
{
    int data = tmpX + tmpY;
    if (data <= 1)
        return 0;
    int loopNum = sqrt(data);
    for (int i = 2; i <= loopNum; i++)
    {
        if (data % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int dfs(int tmpOddPos)
{
    int i;
    for (i = 0; i < EvenNum; i++)
    {
        if (Odd2Even[tmpOddPos][i]==1 && !visited[i])
        {
            visited[i] = 1;
            if (Result[i] == 0 || dfs(Result[i]-1))
            {
                Result[i] = tmpOddPos+1;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int a;
    int N,i;
    while (scanf("%d", &N) != EOF)
    {
        ansNum=0;
        EvenNum = 0;
        OddNum = 0;
        memset(Result, 0, sizeof(Result));
        memset(Odd2Even, 0, sizeof(Odd2Even));
        if (N % 2 != 0)
            break;
        for ( i = 0; i < N; i++)
        {
            scanf("%d", &a);
            if (a % 2 == 0)
            {//建立偶数队列
                EvenArray[EvenNum++] = a;
            }
            else
            {//建立奇数队列
                OddArray[OddNum++] = a;
            }
        }

    for (i = 0; i < OddNum; i++)
        for (int j = 0; j < EvenNum; j++)
        {
            if (isSuShuPairs(OddArray[i], EvenArray[j]))
                Odd2Even[i][j] = 1;
        }
    for (i = 0; i < OddNum; i++)
    {
        memset(visited, 0, sizeof(visited));
        if (dfs(i))
            ansNum++;
    }
    printf("%d\n", ansNum);
    }
    return 0;
}