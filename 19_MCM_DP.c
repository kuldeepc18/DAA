#include <stdio.h>
#include <limits.h>

int matrixChainMultiplication(int dimensions[], int n)
{
    int dp[n][n];

    for (int i = 1; i < n; i++)
    {
        dp[i][i] = 0;
    }

    for (int length = 2; length < n; length++)
    {
        for (int i = 1; i < n - length + 1; i++)
        {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n - 1];
}

int main()
{
    int dimensions[] = {5, 4, 6, 2, 9};
    int n = sizeof(dimensions) / sizeof(dimensions[0]);

    int minimumMultiplications = matrixChainMultiplication(dimensions, n);

    printf("Minimum number of scalar multiplications: %d\n", minimumMultiplications);

    return 0;
}
