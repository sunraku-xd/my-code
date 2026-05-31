
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("Enter number of nodes in the graph: ");
    scanf("%d", &n);

    int **arr = (int **)malloc(sizeof(int *) * n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)calloc(n, sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == j){
                arr[i][j] = 0;
            }
            else{
                printf("Enter edge from %d to %d(0 if no edge): ", i, j);
                scanf("%d", &arr[i][j]);
            }
        }
    }

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;

}