// #include <stdio.h>
// #include <conio.h>
// #include <stdlib.h>

// void main()
// {
//     int rows1, cols1;
//     int i, j;
//     int m1, m2, m3, m4, m5, m6, m7, p1, p2, p3, p4;
//     int **matrix1 = (int **)malloc(rows1 * sizeof(int *));
//     int **matrix2 = (int **)malloc(rows1 * sizeof(int *));
//     int **matrix3 = (int **)malloc(rows1 * sizeof(int *));
//     clrscr();
//     printf("Enter rows and columns for the matrix: ");
//     scanf("%d %d", &rows1, &cols1);
//     for (i = 0; i < rows1; i++)
//     {
//         matrix1[i] = (int *)malloc(cols1 * sizeof(int));
//         if (matrix1[i] == NULL)
//         {
//             printf("Memory Allocation failed");
//             return -1;
//         }
//     }
//     for (i = 0; i < rows1; i++)
//     {
//         matrix2[i] = (int *)malloc(cols1 * sizeof(int));
//         if (matrix2[i] == NULL)
//         {
//             printf("Memory Allocation failed");
//             return -1;
//         }
//     }
//     for (i = 0; i < rows1; i++)
//     {
//         matrix3[i] = (int *)malloc(cols1 * sizeof(int));
//         if (matrix3[i] == NULL)
//         {
//             printf("Memory Allocation failed");
//             return -1;
//         }
//     }
//     printf("\nEnter the first matrix:");
//     for (i = 0; i < rows1; i++)
//     {
//         for (j = 0; j < cols1; j++)
//         {
//             scanf("%d", &matrix1[i][j]);
//         }
//     }
//     printf("\nEnter the second matrix:");
//     for (i = 0; i < rows1; i++)
//     {
//         for (j = 0; j < cols1; j++)
//         {
//             scanf("%d", &matrix2[i][j]);
//         }
//     }
//     m1 = matrix1[0][0] * (matrix2[0][1] - matrix2[1][1]);
//     m2 = (matrix1[0][0] + matrix1[0][1]) * matrix2[1][1];
//     m3 = (matrix1[1][0] + matrix1[1][1]) * matrix2[0][0];
//     m4 = matrix1[1][1] * (matrix2[1][0] - matrix2[0][0]);
//     m5 = (matrix1[0][0] + matrix1[1][1]) * (matrix2[0][0] + matrix2[1][1]);
//     m6 = (matrix1[0][1] - matrix1[1][1]) * (matrix2[1][0] + matrix2[1][1]);
//     m7 = (matrix1[0][0] - matrix1[1][0]) * (matrix2[0][0] + matrix2[0][1]);
//     matrix3[0][0] = m5 + m4 - m2 + m6;
//     matrix3[0][1] = m1 + m2;
//     matrix3[1][0] = m3 + m4;
//     matrix3[1][1] = m1 + m5 - m3 - m7;
//     printf("\nMatrix Multiplication:\n");
//     for (i = 0; i < rows1; i++)
//     {
//         for (j = 0; j < cols1; j++)
//         {
//             printf("%d ", matrix3[i][j]);
//         }
//         printf("\n");
//     }
//     getch();
// }
#include <stdio.h>
#include <stdlib.h>

#define N 4

void add_matrices(int (*A)[N], int (*B)[N], int (*C)[N])
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtract_matrices(int (*A)[N], int (*B)[N], int (*C)[N])
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassen_algorithm(int (*A)[N], int (*B)[N], int (*C)[N])
{
    if (N == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int A11[N / 2][N / 2], A12[N / 2][N / 2], A21[N / 2][N / 2], A22[N / 2][N / 2];
    int B11[N / 2][N / 2], B12[N / 2][N / 2], B21[N / 2][N / 2], B22[N / 2][N / 2];
    int C11[N / 2][N / 2], C12[N / 2][N / 2], C21[N / 2][N / 2], C22[N / 2][N / 2];
    int M1[N / 2][N / 2], M2[N / 2][N / 2], M3[N / 2][N / 2], M4[N / 2][N / 2], M5[N / 2][N / 2], M6[N / 2][N / 2], M7[N / 2][N / 2];
    int temp1[N / 2][N / 2], temp2[N / 2][N / 2];

    // Divide matrices A and B into submatrices
    for (int i = 0; i < N / 2; ++i)
    {
        for (int j = 0; j < N / 2; ++j)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + N / 2];
            A21[i][j] = A[i + N / 2][j];
            A22[i][j] = A[i + N / 2][j + N / 2];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + N / 2];
            B21[i][j] = B[i + N / 2][j];
            B22[i][j] = B[i + N / 2][j + N / 2];
        }
    }

    // Calculate 7 products recursively
    subtract_matrices(B12, B22, temp1);
    strassen_algorithm(A11, temp1, M1);

    add_matrices(A11, A12, temp1);
    strassen_algorithm(temp1, B22, M2);

    add_matrices(A21, A22, temp1);
    strassen_algorithm(temp1, B11, M3);

    subtract_matrices(B21, B11, temp1);
    strassen_algorithm(A22, temp1, M4);

    add_matrices(A11, A22, temp1);
    add_matrices(B11, B22, temp2);
    strassen_algorithm(temp1, temp2, M5);

    subtract_matrices(A12, A22, temp1);
    add_matrices(B21, B22, temp2);
    strassen_algorithm(temp1, temp2, M6);

    subtract_matrices(A21, A11, temp1);
    add_matrices(B11, B12, temp2);
    strassen_algorithm(temp1, temp2, M7);

    // Calculate submatrices of C
    add_matrices(M5, M4, temp1);
    subtract_matrices(temp1, M2, temp2);
    add_matrices(temp2, M6, C11);

    add_matrices(M1, M2, C12);
    add_matrices(M3, M4, C21);

    add_matrices(M5, M1, temp1);
    subtract_matrices(temp1, M3, temp2);
    subtract_matrices(temp2, M7, C22);

    // Combine submatrices into C
    for (int i = 0; i < N / 2; ++i)
    {
        for (int j = 0; j < N / 2; ++j)
        {
            C[i][j] = C11[i][j];
            C[i][j + N / 2] = C12[i][j];
            C[i + N / 2][j] = C21[i][j];
            C[i + N / 2][j + N / 2] = C22[i][j];
        }
    }
}

void print_matrix(int matrix[N][N])
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int A[N][N] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12},
                   {13, 14, 15, 16}};
    int B[N][N] = {{17, 18, 19, 20},
                   {21, 22, 23, 24},
                   {25, 26, 27, 28},
                   {29, 30, 31, 32}};
    int C[N][N];

    // Perform matrix multiplication using Strassen's algorithm
    strassen_algorithm(A, B, C);

    // Print the result matrix
    printf("Result matrix:\n");
    print_matrix(C);

    return 0;
}
