#include <stdio.h>
#include <string.h>
#define MAX_X 1000
#define MAX_Y 1000

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int lcs(char *x, char *y)
{
    int m = strlen(x);
    int n = strlen(y);
    int LCS[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                LCS[i][j] = 0;
            else if (x[i - 1] == y[j - 1])
                LCS[i][j] = 1 + LCS[i - 1][j - 1];
            else
                LCS[i][j] = max(LCS[i][j - 1], LCS[i - 1][j]);
        }
    }
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%d  ", LCS[i][j]);
        }
        printf("\n");
    }
    return LCS[m][n];
}

int main()
{
    char x[] = "ABCBDAB";
    char y[] = "BDCAB";
    int LCS = lcs(x, y);
    printf("Longest Common Subsequence is %d", LCS);
    return 0;
}