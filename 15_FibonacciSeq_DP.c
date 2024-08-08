#include <stdio.h>

int fibonacci_dp(int n)
{
    // Base cases for F(0) and F(1)
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }

    // Create a DP table to store Fibonacci numbers
    int dp[50];

    // Initialize the first two values
    dp[0] = 0;
    dp[1] = 1;

    // Fill the DP table using bottom-up approach
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // Return the nth Fibonacci number from the DP table
    return dp[n];
}

int main()
{
    int n;

    printf("Enter the index of the Fibonacci number (0-based): ");
    scanf("%d", &n);

    int result = fibonacci_dp(n);
    printf("The %dth Fibonacci number is: %d\n", n, result);

    return 0;
}
