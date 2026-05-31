#include <stdio.h>

void printArray(int *arr, int size);
void quickSort(int *arr, int start, int end);
int partition(int *arr, int start, int end);
void swap(int *x, int *y);

int main()
{
    int size = 5;
    int arr[5] = {7, 23, 3, 17, 8};
    int start = 0;
    int end = size - 1;

    printf("Array before sorting:\n");
    printArray(arr, size);

    quickSort(arr, start, end);
    printf("\nArray after sorting:\n");
    printArray(arr, size);

    return 0;
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}

void quickSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int pivot_Idx = partition(arr, start, end);
        quickSort(arr, start, pivot_Idx - 1);
        quickSort(arr, pivot_Idx + 1, end);
    }
}

int partition(int *arr, int start, int end)
{
    int idx = start - 1;
    int pivot = arr[end];
    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            idx++;
            swap(&arr[j], &arr[idx]);
        }
    }
    idx++;
    swap(&arr[end], &arr[idx]);

    return idx;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}