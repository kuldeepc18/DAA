#include <stdio.h>

#define MAX_SIZE 100 // Maximum size for the array

// Function to partition the array
int partition(int a[], int lb, int ub)
{
    int pivot = a[lb];
    int start = lb;
    int end = ub;

    while (start < end)
    {
        while (a[start] <= pivot)
        {
            start++;
        }
        while (a[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }
    // Place pivot in its correct position
    a[lb] = a[end];
    a[end] = pivot;
    return end;
}

// Function to perform Quick Sort
void quicksort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(a, lb, ub);
        quicksort(a, lb, loc - 1);
        quicksort(a, loc + 1, ub);
    }
}

int main()
{
    int n;
    printf("\nEnter the number of elements to be sorted (up to %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE)
    {
        printf("Invalid input for array size.\n");
        return 1; // Exit with failure status
    }

    int a[MAX_SIZE];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element no. %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    quicksort(a, 0, n - 1);
    printf("\nSorted array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
