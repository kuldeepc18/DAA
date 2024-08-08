#include <stdio.h> // Includes the standard input/output header for functions like printf

#define MAX 100
// All denominations of Indian Currency
int denomination[] = {1, 2, 5};                      // An array to store the available denominations
int n = sizeof(denomination) / sizeof(denomination[0]); // Calculates the number of elements in the denomination array

void findMin(int V)
{
    // Sorts the denominations in descending order using bubble sort
    for (int i = 0; i < n - 1; i++)
    { // Outer loop for number of passes
        for (int j = 0; j < n - i - 1; j++)
        { // Inner loop to compare adjacent elements
            if (denomination[j] < denomination[j + 1])
            {                                          // Check if elements are in descending order
                int temp = denomination[j];            // Temporary variable to hold the larger value
                denomination[j] = denomination[j + 1]; // Swap smaller value to the left
                denomination[j + 1] = temp;            // Swap larger value to the right
            }
        }
    }

    // Initialize result array with a size equal to the value V
    int ans[100];    // Array to store the combination of denominations used
    int count = 0; // Keeps track of the number of coins used

    // Traverse through all denominations
    for (int i = 0; i < n; i++)
    {
        // Find denominations
        while (V >= denomination[i])
        {                                   // Loop until the value V is less than the current denomination
            V -= denomination[i];           // Subtract the denomination from the value
            ans[count++] = denomination[i]; // Add the denomination to the result array and increment the count
        }
    }

    // Print result
    printf("Following is minimal number of change for %d : ", V);
    for (int i = 0; i < count; i++)
    {
        printf("%d ", ans[i]); // Print each denomination used
    }
    printf("\n");

    // Print the size of the ans array
    printf("Minimum number of coins required : %d\n", count);
}

int main()
{
    int value = 6; // The value for which we want to find the minimum number of coins
    findMin(value); // Call the findMin function to calculate the minimum coins
    return 0;       // Indicates successful program termination
}
