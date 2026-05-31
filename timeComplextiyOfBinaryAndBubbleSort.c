#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct Array
{
    int *Array;
    int sizeOfArray;
    bool timeComplexitiFlag;
} Array;

int *createArray(int size);
void scanArray(Array arr);
void printArrray(Array arr);
void assignValuetoArray(Array arr);
void bubbleSort(Array arr, bool vFlag);
int binarySearch(Array arr, int key);
void reverslySortedNumbeAssign(Array arr);
void sortedNumberAssign(Array arr);

int main()
{
    Array array;
    int validIndex;
    int key;
    printf("Enter the size of Array: ");
    scanf("%d", &array.sizeOfArray);
    array.Array = createArray(array.sizeOfArray);
    assignValuetoArray(array);
    printArrray(array);
    printf("The Array before sorting\n");
    printArrray(array);
    printf("The Array after the sorting\n");
    array.timeComplexitiFlag = false;
    bubbleSort(array, false);
    printArrray(array);
    printf("Enter the number for search: ");
    scanf("%d", &key);
    validIndex = binarySearch(array, key);
    if (validIndex != -1)
    {
        printf("The number %d is at index %d of the Array.\n", key, validIndex);
    }
    else
    {
        printf("The number %d is not present in the Array.\n", key);
    }
    printf("The time complexity shown.\n");

    for (int i = 2; i <= 1024; i *= 2)
    {
        Array arr;
        arr.Array = createArray(i);
        arr.sizeOfArray = i;
        reverslySortedNumbeAssign(arr);
        arr.timeComplexitiFlag = true;
        bubbleSort(arr, false);
        free(arr.Array);
    }
    printf("\n");
    for (int i = 2; i <= 1024; i *= 2)
    {
        Array arr;
        arr.Array = createArray(i);
        arr.sizeOfArray = i;
        sortedNumberAssign(arr);
        arr.timeComplexitiFlag = true;
        binarySearch(arr, 1024);
        free(arr.Array);
    }

    free(array.Array);
    return 0;
}
int *createArray(int size)
{
    return (int *)malloc(sizeof(int) * size);
}
void scanArray(Array arr)
{
    for (int i = 0; i < arr.sizeOfArray; i++)
    {
        printf("Enter the number for Array[%d]: ", (i + 1));
        scanf("%d", &arr.Array[i]);
    }
}
void printArrray(Array arr)
{
    for (int i = 0; i < arr.sizeOfArray; i++)
    {
        printf("%d\t", arr.Array[i]);
    }
    printf("\n");
}
void assignValuetoArray(Array arr)
{
    srand(time(NULL));
    for (int i = 0; i < arr.sizeOfArray; i++)
    {
        arr.Array[i] = (rand() % 100);
    }
}
void bubbleSort(Array arr, bool vFlag)
{
    int comparisonCount = 0;
    for (int i = 0; i < arr.sizeOfArray - 1; i++)
    {
        bool earlyTermination = true;
        for (int j = 0; j < arr.sizeOfArray - i - 1; j++)
        {
            if (arr.Array[j] > arr.Array[j + 1])
            {
                int temp = arr.Array[j];
                arr.Array[j] = arr.Array[j + 1];
                arr.Array[j + 1] = temp;
                earlyTermination = false;
                comparisonCount++;
            }
        }
        if (earlyTermination)
            break;
        if (vFlag)
            printArrray(arr);
    }
    if (arr.timeComplexitiFlag)
        printf("The Array of size %4d with %6d many comparisons in bubble sort.\n", arr.sizeOfArray, comparisonCount);
}
int binarySearch(Array arr, int key)
{
    int start = 0;
    int end = arr.sizeOfArray - 1;
    int mid = start + (end - start) / 2;
    int index = -1;
    int comparisonCount = 0;
    while (start <= end && arr.Array[mid] != key)
    {
        if (arr.Array[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
        comparisonCount++;
    }
    if (start <= end)
        index = mid;
    if (arr.timeComplexitiFlag)
        printf("The Array of %4d with %2d many comparisons in binary search.\n", arr.sizeOfArray, comparisonCount);
    return index;
}
void reverslySortedNumbeAssign(Array arr)
{
    for (int i = 0; i < arr.sizeOfArray; i++)
    {
        arr.Array[i] = (arr.sizeOfArray - i - 1);
    }
}
void sortedNumberAssign(Array arr)
{
    for (int i = 0; i < arr.sizeOfArray; i++)
    {
        arr.Array[i] = i;
    }
}

