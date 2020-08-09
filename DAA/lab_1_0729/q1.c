#include <stdio.h>
#include <stdlib.h>

int largest(int arr[], int n)
{
    int i;
    int max = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

int smallest(int arr[], int n)
{
    int i;
    int min = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] < min)
            min = arr[i];

    return min;
}

int main()
{
    int length = 0;
    printf("Enter the length of the array: ");
    scanf("%d",&length);
    int arr[length];
    for (int i = 0; i < length; i++)
    {
        arr[i] = rand()%99;
    }
    printf("The Array :\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nLargest = %d", largest(arr, sizeof(arr) / sizeof(arr[0])));
    printf("\nSmallest = %d", smallest(arr, sizeof(arr) / sizeof(arr[0])));
    printf("\n");
    return 0;
}