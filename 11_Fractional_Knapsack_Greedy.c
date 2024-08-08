#include <stdio.h>

#define MAX_FRUITS 100 // Maximum number of fruits

// Function to swap two floating-point numbers
void swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

// Function to solve the fractional knapsack problem
float fractionalKnapsack(int n, float k, float w[], float nu[])
{
    float ratio[MAX_FRUITS]; // Array to store the ratio of nutrition to weight for each fruit
    int i;
    float total_nutrition = 0.0; // Variable to store the total nutrition value obtained

    // Calculate the ratio of nutrition to weight for each fruit
    for (i = 0; i < n; i++)
    {
        ratio[i] = nu[i] / w[i];
    }

    // Sort the fruits based on their ratio of nutrition to weight in non-increasing order
    for (i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                // Swap the positions of fruits based on their ratio of nutrition to weight
                swap(&ratio[i], &ratio[j]);
                swap(&w[i], &w[j]);
                swap(&nu[i], &nu[j]);
            }
        }
    }

    // Iterate through the sorted fruits and add them to the knapsack until it's full
    for (i = 0; i < n; i++)
    {
        if (k > w[i])
        {
            // If the knapsack can accommodate the entire weight of the fruit, add its full nutrition value
            total_nutrition += ratio[i] * w[i];
            k -= w[i];
        }
        else if (k == w[i])
        {
            // If the knapsack can exactly accommodate the weight of the fruit, add its full nutrition value and return
            total_nutrition += ratio[i] * w[i];
            return total_nutrition;
        }
        else
        {
            // If the knapsack cannot accommodate the entire weight of the fruit, add a fraction of its nutrition value
            total_nutrition += k * ratio[i];
            return total_nutrition;
        }
    }

    return total_nutrition;
}

int main()
{
    float k;  // Knapsack capacity
    int n, i; // Number of fruits and loop variable

    // Prompt the user to enter the knapsack capacity
    printf("Enter the knapsack value: ");
    scanf("%f", &k);

    // Prompt the user to enter the number of fruits
    printf("\nEnter the number of fruits (up to 100): ");
    scanf("%d", &n);

    // Check if the number of fruits is within the acceptable range
    if (n <= 0 || n > MAX_FRUITS)
    {
        printf("Invalid number of fruits.\n");
        return 1; // Return non-zero to indicate an error
    }

    // Arrays to store the weight and nutrition value of each fruit
    float weight[MAX_FRUITS], nutrition[MAX_FRUITS];

    // Prompt the user to enter the weight of each fruit
    printf("\nEnter the weight of all fruits: ");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &weight[i]);
    }

    // Prompt the user to enter the nutrition value of each fruit
    printf("\nEnter the nutrition value of all fruits: ");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &nutrition[i]);
    }

    // Calculate the maximum nutrition value that can be obtained from the fractional knapsack problem
    float max_nutrition = fractionalKnapsack(n, k, weight, nutrition);

    // Print the maximum nutrition value
    printf("\nMaximum nutrition value: %.2f\n", max_nutrition);

    return 0;
}
