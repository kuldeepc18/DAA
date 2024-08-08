#include <stdio.h>
#include <stdlib.h>

// int min(int a, int b){
//     return (a < b) ? a : b;
// }

int min(int a, int b)
{

    if (a < b)
        return a;
    else
        return b;
}
int main()
{
    int n, amount, i;
    printf("Enter the number of coins : ");
    scanf("%d", &n);

    int coins[n];
    printf("Enter your coins here : ");
    for (i = 0; i < n; i++)
        scanf("%d", &coins[i]);
    printf("Enter an amount you need to form : ");
    scanf("%d", &amount);

    int d[n][amount + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (j == 0)
                d[i][j] = 0;
            else if (coins[i] > j)
            {
                if (i == 0)
                    d[i][j] = 100;
                else
                    d[i][j] = d[i - 1][j];
            }
            else
            {
                if (i == 0)
                    d[i][j] = 1 + d[i][j - coins[i]];
                else
                    d[i][j] = min(d[i - 1][j], 1 + d[i][j - coins[i]]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            printf("%d  ", d[i][j]);
        }
        printf("\n");
    }

    printf("%d", d[n - 1][amount]);
    int value = amount, i1 = n - 1;
    while (value > 0 && i1 >= 0)
    {
        if (d[i1][value] == d[i1 - 1][value])
            i1--;
        else
        {
            printf("%d  ", coins[i1]);
            value -= coins[i1];
        }
    }

    return 0;
}