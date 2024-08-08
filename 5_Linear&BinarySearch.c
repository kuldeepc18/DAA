#include <stdio.h>
#include <stdlib.h>

#define size 20
void LinearSearch();
void BinarySearch();

int arr[size], val, i, n, found = 0, pos = -1, beg, end, mid;

int main()
{
    while (1)
    {
        int choice;
        printf("\nEnter a choice: ");
        printf("\n1. Linear Search");
        printf("\n2. Binary Search\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            LinearSearch();
            break;
        case 2:
            BinarySearch();
            break;
        default:
            printf("Choice does not exit");
            exit(0);
        }
    }
    return 0;
}

void LinearSearch()
{
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);

    printf("\n Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the number that has to be searched: ");
    scanf("%d", &val);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == val)
        {
            found = 1;
            pos = i;
            if (arr[i] == pos + 1)
            {
                printf("\n%d is found at position = %d", val, pos + 1);
            }
            else if (arr[i] == pos - 1)
            {
                printf("\n%d is found at position = %d", val, pos - 1);
            }
            printf("\n%d is found at position = %d", val, pos);
            break;
        }
    }
    if (found == 0)
    {
        printf("%d does not exist!", val);
    }
}

void BinarySearch()
{
    printf("\n Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("\nEnter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the number that has to be searched: ");
    scanf("%d", &val);
    beg = 0;
    end = n - 1;
    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (arr[mid] == val)
        {
            printf("\n%d is at position %d", val, mid + 1);
            found = 1;
            break;
        }
        else if (arr[mid] > val)
        {
            end = mid - 1;
        }
        else
        {
            beg = mid + 1;
        }
    }
    if (beg > end && found == 0)
    {
        printf("\n%d does not exist", val);
    }
}
