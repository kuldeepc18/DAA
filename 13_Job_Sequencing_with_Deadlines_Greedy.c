#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapS(char *a, char *b)
{
    char temp[50];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

int main()
{
    printf("Enter the no. of Jobs: ");
    int n, i, j;
    scanf("%d", &n);
    char(*jobs)[50] = malloc(n * sizeof(char[50])); // Allocate memory for job names
    int *deadline = malloc(n * sizeof(int));        // Allocate memory for deadlines
    int *profit = malloc(n * sizeof(int));          // Allocate memory for profits

    if (jobs == NULL || deadline == NULL || profit == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1; // Return error code
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter the Job no.: ");
        scanf("%s", jobs[i]);
        printf("Enter the deadline and profit of job %s: ", jobs[i]);
        scanf("%d %d", &deadline[i], &profit[i]);
    }

    // Sort jobs based on profit in decreasing order
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (profit[j] < profit[j + 1])
            {
                swap(&profit[j], &profit[j + 1]);
                swap(&deadline[j], &deadline[j + 1]);
                swapS(jobs[j], jobs[j + 1]);
            }
        }
    }

    printf("\n\n");
    printf("Hence, the Sorting in descending order of their Profits is: \n");
    printf("Jobs\t  Deadline\tProfits\n");
    for (i = 0; i < n; i++)
        printf(" %s     \t%d\t    %d\n", jobs[i], deadline[i], profit[i]);

    // Find max deadline
    int max = deadline[0];
    for (i = 1; i < n; i++)
    {
        if (max < deadline[i])
            max = deadline[i];
    }

    char(*sol)[50] = malloc(max * sizeof(char[50])); // Allocate memory for solution array

    if (sol == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1; // Return error code
    }

    // Initialize solution array
    for (i = 0; i < max; i++)
        strcpy(sol[i], "-");

    // Assign jobs to slots based on deadlines
    for (i = 0; i < n; i++)
    {
        int d = deadline[i] - 1;
        while (d >= 0)
        {
            if (strcmp(sol[d], "-") == 0)               //if the slot is empty
            {
                strcpy(sol[d], jobs[i]);
                break;
            }
            else
                d--;
        }
    }

    printf("\nJob sequence:\n");
    for (i = 0; i < max; i++)
    {
        if (strcmp(sol[i], "-") == 0)
            printf("Slot %d: Empty\n", i + 1);
        else
            printf("Slot %d: %s\n", i + 1, sol[i]);
    }

    // Free dynamically allocated memory
    free(jobs);
    free(deadline);
    free(profit);
    free(sol);

    return 0;
}
