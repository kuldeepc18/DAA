#include <stdio.h> // Includes standard input/output library for functions like printf and scanf

// Define arrays to store activity data (maximum 100 activities)
int activity[100], start[100], finish[100];
int solution[100]; // Array to store the scheduled activities

// Function to swap two integer values (used for sorting)
void swap(int *a, int *b)
{
    int temp = *a; // Stores the value of a in a temporary variable
    *a = *b;       // Assigns the value of b to a
    *b = temp;     // Assigns the stored value of a (now in temp) to b
}

int main()
{
    int n, i, j;

    printf("Enter the total number of activities: ");
    scanf("%d", &n); // Get the number of activities from the user

    printf("Enter the activities: \n");
    // Get activity names (assumed to be integer values) from the user
    for (i = 0; i < n; i++)
    {
        scanf("%d", &activity[i]);
    }

    printf("Enter the start time: \n");
    // Get start times for each activity from the user
    for (i = 0; i < n; i++)
    {
        scanf("%d", &start[i]);
    }

    printf("Enter the finish time: \n");
    // Get finish times for each activity from the user
    for (i = 0; i < n; i++)
    {
        scanf("%d", &finish[i]);
    }

    // Sort activities according to their finish time (bubble sort implementation)
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (finish[j] > finish[j + 1])
            {                                         // Check if current finish time is greater than the next one
                swap(&finish[j], &finish[j + 1]);     // Swap finish times if necessary
                swap(&start[j], &start[j + 1]);       // Swap start times to maintain order
                swap(&activity[j], &activity[j + 1]); // Swap activity names to maintain order
            }
        }
    }

    printf("Sorted activities according to their finish time.\n");
    printf("start time(s)\tfinish time(f)\tactivity name\n");
    // Print the sorted activity list with start times, finish times, and names
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\n", start[i], finish[i], activity[i]);
    }

    int k = 0;                 // Index for the solution array
    solution[k] = activity[0]; // Add the first activity to the solution (always included)
    for (i = 1; i < n; i++)
    {
        if (start[i] >= finish[k])
        {                              // Check if the current activity can start after the previous one finishes
            k++;                       // Increment index for the next activity in the solution
            solution[k] = activity[i]; // Add the current activity to the solution
        }
    }

    printf("Hence the schedule is: \n");
    // Print the scheduled activities in order
    for (i = 0; i < k; i++)
    {
        printf("%d --> ", solution[i]);
    }
    printf("%d\n", solution[k]); // Print the last activity in the schedule

    return 0; // Indicate successful program termination
}
