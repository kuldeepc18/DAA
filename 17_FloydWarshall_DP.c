#include <stdio.h>
#include <limits.h>

void printMatrix(int nV, int matrix[][nV]);
void floydWarshall(int nV, int graph[][nV]);

int main()
{
    int nV;
    printf("Enter the number of vertices: ");
    scanf("%d", &nV);
    int graph[nV][nV];

    printf("Enter the adjacency matrix of size (%d x %d) : \n", nV, nV);
    for (int i = 0; i < nV; i++)
        for (int j = 0; j < nV; j++)
        {
            printf("Matrix[%d][%d] : ", i + 1, j + 1);
            scanf("%d", &graph[i][j]);
        }
    floydWarshall(nV, graph);
    return 0;
}

void floydWarshall(int nV, int graph[][nV])
{
    int dist[nV][nV], pred[nV][nV];

    for (int i = 0; i < nV; i++)
        for (int j = 0; j < nV; j++)
        {
            dist[i][j] = graph[i][j];
            if (graph[i][j] != INT_MAX && i != j)
                pred[i][j] = i + 1;
            else
                pred[i][j] = 0;
        }

    for (int k = 0; k < nV; k++)
    {
        for (int i = 0; i < nV; i++)
        {
            for (int j = 0; j < nV; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = pred[k][j];
                }
            }
        }
    }

    printf("\nDistance Matrix:\n");
    printMatrix(nV, dist);

    printf("\nPredecessor Matrix:\n");
    printMatrix(nV, pred);
}

void printMatrix(int nV, int matrix[][nV])
{
    for (int i = 0; i < nV; i++)
    {
        for (int j = 0; j < nV; j++)
        {
            if (matrix[i][j] == INT_MAX)
                printf("INF ");
            else
                printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
