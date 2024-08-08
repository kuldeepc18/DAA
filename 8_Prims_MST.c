#include <stdio.h>
#include <stdlib.h>

#define infinity 999
#define MAX 20

int G[MAX][MAX], spanning[MAX][MAX], n;

int prims();

int main()
{
    // Prompt user for number of vertices
    printf("Enter no. of vertices:");
    scanf("%d", &n);

    // Read in adjacency matrix
    printf("\nEnter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    // Calculate minimum spanning tree
    int total_cost = prims();

    // Print spanning tree matrix
    printf("\nspanning tree matrix:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
            printf("%d\t", spanning[i][j]);
    }

    // Print total cost of spanning tree
    printf("\n\nTotal cost of spanning tree=%d", total_cost);

    return 0;
}

int prims()
{
    // Initialize cost matrix and spanning tree matrix
    int cost[MAX][MAX];
    int u, v, min_distance, distance[MAX], from[MAX];
    int visited[MAX], no_of_edges, i, min_cost, j;

    // Initialize cost matrix and spanning tree matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (G[i][j] == 0)
                cost[i][j] = infinity;
            else
                cost[i][j] = G[i][j];
            spanning[i][j] = 0;
        }

    // Initialize visited[], distance[] and from[]
    distance[0] = 0;
    visited[0] = 1;
    for (i = 1; i < n; i++)
    {
        distance[i] = cost[0][i];
        from[i] = 0;
        visited[i] = 0;
    }

    // Initialize minimum cost and number of edges
    min_cost = 0;
    no_of_edges = n - 1;

    // Find minimum spanning tree
    while (no_of_edges > 0)
    {
        // Find the vertex at minimum distance from the tree
        min_distance = infinity;
        for (i = 1; i < n; i++)
            if (visited[i] == 0 && distance[i] < min_distance)
            {
                v = i;
                min_distance = distance[i];
            }

        // Insert the edge in spanning tree
        u = from[v];
        spanning[u][v] = distance[v];
        spanning[v][u] = distance[v];

        // Decrement number of edges
        no_of_edges--;

        // Mark vertex as visited
        visited[v] = 1;

        // Update distance[] array
        for (i = 1; i < n; i++)
            if (visited[i] == 0 && cost[i][v] < distance[i])
            {
                distance[i] = cost[i][v];
                from[i] = v;
            }

        // Add cost of edge to minimum cost
        min_cost = min_cost + cost[u][v];
    }

    // Return minimum cost
    return (min_cost);
}