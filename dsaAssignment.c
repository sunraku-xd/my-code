#include <stdio.h>
#include <stdlib.h>

// Function Declaration
int *createArray(int size);
void scanArray(int *arr, int size);
void printArray(int *arr, int size);
int linearSearch(int *arr, int size, int key);
int binarySearch(int *arr, int size, int key);
void bubbleSort(int *arr, int size);
void selectionSort(int *arr, int size);
void insertionSort(int *arr, int size);
void mergeSort(int *arr, int start, int end);
void merge(int *arr, int start, int mid, int end);
void quickSort(int *arr, int start, int end);
int partition(int *arr, int start, int end);
void heapSort(int *arr, int size);
void buildHeap(int *arr, int size);
void heapify(int *arr, int I, int size);
void swap(int *x, int *y);

// Main Function
int main()
{

    int *arr, size, choice;
    int key, pos_1, pos_2;

    do
    {

        printf("\n<MENU>\n");
        printf("1.Input DAta\n");
        printf("2.Display\n");
        printf("3.Linear Search\n");
        printf("4.Binary Search\n");
        printf("5.Bubble Sort\n");
        printf("6.Selection Sort\n");
        printf("7.Insertion Sort\n");
        printf("8.Merge Sort\n");
        printf("9.Quick Sort\n");
        printf("10.Heap sort\n");
        printf("11.Exit\n");

        int choice = 0;
        printf("\n##Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:

            printf("Enter the Array size: ");
            scanf("%d", &size);

            arr = createArray(size);
            scanArray(arr, size);

            int start = 0;
            int end = size - 1;

            break;

        case 2:

            printf("Array elements are:\n");
            printArray(arr, size);
            printf("\n");

            break;

        case 3:

            printf("\nEnter element to search:");
            scanf("%d", &key);

            pos_1 = linearSearch(arr, size, key);

            if (pos_1 != -1)
            {
                printf("(ls)Element found at position: %d\n", pos_1 + 1);
            }
            else
            {
                printf("Element not found.\n");
            }

            break;

        case 4:

            printf("\nSorted Array:\n");
            bubbleSort(arr, size);
            printArray(arr, size);

            printf("\nEnter element to search:");
            scanf("%d", &key);

            pos_2 = binarySearch(arr, size, key);

            if (pos_2 != -1)
            {
                printf("(bs)Element found at position: %d\n", pos_2 + 1);
            }
            else
            {
                printf("Element not found.\n");
            }

            break;

        case 5:

            printf("\nArray elements after using Bubble Sort:\n");
            bubbleSort(arr, size);
            printArray(arr, size);
            printf("\n");

            break;

        case 6:

            printf("\nArray elements after using Selection Sort:\n");
            selectionSort(arr, size);
            printArray(arr, size);
            printf("\n");

            break;

        case 7:

            printf("\nArray elements after using Insertion Sort:\n");
            insertionSort(arr, size);
            printArray(arr, size);
            printf("\n");

            break;

        case 8:

            printf("\nArray elements after using Merge Sort:\n");
            mergeSort(arr, start, end);
            printArray(arr, size);
            printf("\n");

            break;

        case 9:

            printf("\nArray elements after using Quick Sort:\n");
            quickSort(arr, start, end);
            printArray(arr, size);
            printf("\n");

            break;

        case 10:

            printf("\nArray elements after using Heap Sort:\n");
            heapSort(arr, size);
            printArray(arr, size);
            printf("\n");

            break;

        case 11:

            exit(0);
        }

    } while (choice != 11);

    free(arr);

    return 0;
}

// Function Defination
int *createArray(int size)
{

    return (int *)calloc(size, sizeof(int));
}

void scanArray(int *arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        printf("Enter Arr[%d]: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void printArray(int *arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}

int linearSearch(int *arr, int size, int key)
{

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int *arr, int size, int key)
{

    int start = 0;
    int end = size - 1;
    while (start <= end)
    {

        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

void bubbleSort(int *arr, int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selectionSort(int *arr, int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] > arr[minIdx])
            {
                minIdx = j;
            }
            swap(&arr[j], &arr[minIdx]);
        }
    }
}

void insertionSort(int *arr, int size)
{

    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void mergeSort(int *arr, int start, int end)
{

    if (start < end)
    {

        int mid = start + ((end - start) / 2);

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
}

void merge(int *arr, int start, int mid, int end)
{

    int n1 = mid - start + 1;
    int n2 = end - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[start + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = start;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }
    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
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

void heapSort(int *arr, int size)
{

    buildHeap(arr, size);
    for (int i = size - 1; i > 0; i--)
    {
        swap(&arr[i], &arr[0]);
        heapify(arr, 0, i);
    }
}

void buildHeap(int *arr, int size)
{

    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        heapify(arr, i, size);
    }
}

void heapify(int *arr, int I, int size)
{

    int left = I * 2 + 1;
    int right = I * 2 + 2;

    int maxIdx = I;

    if (left < size && arr[left] > arr[maxIdx])
    {
        maxIdx = left;
    }
    if (right < size && arr[right] > arr[maxIdx])
    {
        maxIdx = right;
    }
    if (maxIdx != I)
    {
        swap(&arr[I], &arr[maxIdx]);
        heapify(arr, maxIdx, size);
    }
}

void swap(int *x, int *y)
{

    int temp = *x;
    *x = *y;
    *y = temp;
}
