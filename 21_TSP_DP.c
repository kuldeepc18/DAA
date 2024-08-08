#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 4 // Number of vertices in the graph

// Function to find the minimum of two integers
int min(int a, int b)
{
    if a < b
    {
        return a;
    } 
    else
    {
        return b;
    }
}

// Function to solve the Traveling Salesperson Problem using dynamic programming
int tsp(int graph[][V], int mask, int pos, int dp[][V])
{
    // If all vertices have been visited
    if (mask == (1 << V) - 1)
    {
        return graph[pos][0]; // Return cost of going back to the starting city
    }

    // If the subproblem has already been computed
    if (dp[mask][pos] != -1)
    {
        return dp[mask][pos];
    }

    // Initialize minimum cost for this node
    int min_cost = INT_MAX;

    // Try all unvisited cities as next possible destinations
    for (int city = 0; city < V; city++)
    {
        // If the city has not been visited yet
        if ((mask & (1 << city)) == 0)
        {
            int new_mask = mask | (1 << city);                                // Update mask to mark the city as visited
            int new_cost = graph[pos][city] + tsp(graph, new_mask, city, dp); // Calculate cost
            min_cost = min(min_cost, new_cost);                               // Update minimum cost
        }
    }

    // Save the result in the dp table
    dp[mask][pos] = min_cost;

    return min_cost;
}

// Main function
int main()
{
    int graph[V][V] = {{0, 10, 15, 20},
                       {10, 0, 35, 25},
                       {15, 35, 0, 30},
                       {20, 25, 30, 0}};

    // Initialize dp table with -1
    int dp[1 << V][V];
    for (int i = 0; i < (1 << V); i++)
    {
        for (int j = 0; j < V; j++)
        {
            dp[i][j] = -1;
        }
    }

    // Start from the first city (0th index) and compute the minimum cost
    int min_cost = tsp(graph, 1, 0, dp);

    printf("Minimum cost for the Traveling Salesperson Problem: %d\n", min_cost);

    return 0;
}
