#include <stdio.h>  // Include standard input/output library
#include <limits.h> // Include limits library for INT_MAX

#define V 4 // Define number of vertices in the graph

// Function to find the minimum distance vertex
int minDistance(int dist[], int visited[])
{
    int min = INT_MAX, min_index; // Initialize min to maximum integer value
    for (int v = 0; v < V; v++)
    { // Loop through all vertices
        if (visited[v] == 0 && dist[v] <= min)
        {                  // If vertex is not visited and distance is less than min
            min = dist[v]; // Update min value
            min_index = v; // Update min index
        }
    }
    return min_index; // Return minimum distance vertex
}

// Function to print the shortest distances
void printSolution(int dist[])
{
    printf("Vertex\tDistance from Source\n"); // Print header
    for (int i = 0; i < V; i++)
    {                                    // Loop through all vertices
        printf("%d \t%d\n", i, dist[i]); // Print vertex and its distance from source
    }
}

// Dijkstra's algorithm implementation
void dijkstra(int graph[V][V], int src)
{
    int dist[V];    // Distance array
    int visited[V]; // Visited array

    // Initialize distances and visited array
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX; // Initialize all distances to maximum integer value
        visited[i] = 0;    // Initialize all vertices as not visited
    }

    dist[src] = 0; // Distance to source vertex is 0

    for (int count = 0; count < V - 1; count++)
    {                                       // Loop through all vertices except the last one
        int u = minDistance(dist, visited); // Find the minimum distance vertex
        visited[u] = 1;                     // Mark the minimum distance vertex as visited

        for (int v = 0; v < V; v++)
        { // Loop through all vertices
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {                                    // If vertex is not visited, there is an edge between u and v, and the new distance is less than the current distance
                dist[v] = dist[u] + graph[u][v]; // Update the distance of vertex v
            }
        }
    }

    printSolution(dist); // Print the shortest distances
}

int main()
{
    int graph[V][V] = {
        {0, 8, 5, 9},
        {0, 0, 0, 0},
        {0, 4, 0, 1},
        {0, 1, 0, 0}};

    int src = 0;          // Source vertex
    dijkstra(graph, src); // Call Dijkstra's algorithm with source vertex

    return 0;
}