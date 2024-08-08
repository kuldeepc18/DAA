#include <stdio.h>
#include <conio.h> // For using getch()
#include <stdlib.h>

#define MAX_VERTICES 9 // Maximum number of vertices
#define INF 999        // Infinity representing absence of edge

int i, j, k, a, b, u, v, n, ne = 1;                         // Variables for loop indices, vertices, and edges
int min, mincost = 0;                                       // Variables for minimum cost and total minimum cost
int cost[MAX_VERTICES][MAX_VERTICES], parent[MAX_VERTICES]; // Adjacency matrix and parent array

// Function to find the root of a vertex in a set
int find(int);

// Function to perform union operation of two sets
int uni(int, int);

void main()
{
    printf("\n\tImplementation of Kruskal's Algorithm\n");

    // Input the number of vertices
    printf("\nEnter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &n);

    // Input the cost adjacency matrix
    printf("\nEnter the cost adjacency matrix (%d x %d):\n", n, n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            // If the cost is 0 (indicating no edge) and not a diagonal element, replace it with INF
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INF; // Replace zero with infinity, except for diagonal elements
        }
    }

    printf("The edges of Minimum Cost Spanning Tree are\n");

    // Loop until we have n-1 edges in the MST
    while (ne < n)
    {
        // Find the minimum cost edge that is not yet included in the MST
        for (i = 1, min = INF; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    // Store the vertices of the minimum cost edge
                    a = u = i;
                    b = v = j;
                }
            }
        }

        // Find the root of vertex u and vertex v
        u = find(u);
        v = find(v);

        // If including this edge doesn't form a cycle, include it in MST
        if (uni(u, v))
        {
            // Print the edge and its cost, and update the total minimum cost
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }

        // Mark the edge as visited by setting its cost to INF
        cost[a][b] = cost[b][a] = INF;
    }

    // Print the total minimum cost
    printf("\n\tMinimum cost = %d\n", mincost);

    // Wait for a keypress before closing the console window
    getch();
}

// Function to find the root of a vertex in a set
int find(int i)
{
    // Traverse up the parent array until we find the root
    while (parent[i])
        i = parent[i];
    return i;
}

// Function to perform union operation of two sets
int uni(int i, int j)
{
    // If the roots are different, set the parent of j as i
    if (i != j)
    {
        parent[j] = i; // Set parent of j as i
        return 1;      // Return true indicating union is performed
    }
    return 0; // Return false indicating no union is performed
}
