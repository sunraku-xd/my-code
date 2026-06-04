#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int arr[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    int *visited = (int *)calloc(n, sizeof(int));
    int *q = (int *)calloc(n, sizeof(int));
    int front = -1, rear = -1;
    int start = 0;
    q[++rear] = start;
    visited[start] = 1;

    printf("BFS Trversal:\n");
    while (front != rear)
    {
        int current = q[++front];
        for (int i = 0; i < n; i++)
        {
            if (arr[current][i] != 0 && visited[i] == 0)
            {
                visited[i] = 1;
                q[++rear] = i;
            }
        }
        printf("%c  ", current + 65);
    }
    printf("\nGraph Representation:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
