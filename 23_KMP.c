#include <stdio.h>

int main()
{
    int m, n;
    printf("Enter the number of characters in the String : ");
    scanf("%d", &m);
    printf("Enter the number of characters in the Pattern : ");
    scanf("%d", &n);

    char String[m], Pattern[n];

    printf("Enter a String : ");
    for (int i = 0; i < m; i++)
        scanf(" %c", &String[i]);

    printf("Enter a Pattern : ");
    for (int i = 0; i < n; i++)
        scanf(" %c", &Pattern[i]);

    int π[n], length;
    π[0] = 0;
    for (int i = 1; i < n; i++)
    {
        length = π[i - 1];
        while (length > 0 && Pattern[i] != Pattern[length])
            length = π[length - 1];
        if (Pattern[i] == Pattern[length])
            ++length;
        π[i] = length;
    }
    printf("\nHence, Prefix Table for a Pattern will be :-");
    printf("\nPattern -->\t");
    for (int i = 0; i < n; i++)
        printf("%c\t", Pattern[i]);
        
    printf("\nπ       -->\t");
    for (int i = 0; i < n; i++)
        printf("%d\t", π[i]);
    printf("\n");

    int k = 0, j = -1;
    while (j != n - 1)
    {
        if (String[k] == Pattern[j + 1])
        {
            k++;
            j++;
            if (j == n - 1)
            {
                printf("\nGiven Pattern is present in the given String.\n");
                printf("%d", k - j);
            }
        }
        else
        {
            if (j == 0)
                k++;
            else
                j = π[j];
        }
    }
    if (j != n - 1)
        printf("Given Pattern was not found.\n");
    return 0;
}