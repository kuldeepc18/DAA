#include <stdio.h>
#define MAX_VERTICES 100

int adjacency[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int numVertices, numColors;

int promising_colouring(int v);
void colouring(int v);

int promising_colouring(int v)
{
    for (int i = 0; i < v; i++)
        if (adjacency[v][i] && colors[i] == colors[v])
            return 0;
    return 1;
}

void colouring(int v)
{
    if (v == numVertices)
    {
        printf("Vertex Colors: ");
        for (int i = 0; i < numVertices; i++)
            printf("%d ", colors[i]);
        printf("\n");
        return;
    }

    for (int c = 1; c <= numColors; c++)
    {
        colors[v] = c;
        if (promising_colouring(v))
            colouring(v + 1);
        colors[v] = 0;
    }
}

int main()
{
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the number of colors: ");
    scanf("%d", &numColors);

    printf("Enter the adjacency matrix (%d x %d):\n", numVertices, numVertices);
    for (i = 0; i < numVertices; i++)
        for (j = 0; j < numVertices; j++)
            scanf("%d", &adjacency[i][j]);

    for (i = 0; i < numVertices; i++)
        colors[i] = 0;

    colouring(0);
    return 0;
}