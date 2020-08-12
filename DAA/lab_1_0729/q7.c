#include <stdio.h>
#include <stdlib.h>

int randInt(){
    __time_t t;
    srand((unsigned) t*rand());
    return rand()%50;
}


void printArray(int n,int arr[n]){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapNumbers(int arr[], int l, int r)
{
    if (l < r)
    {
        swap(&arr[l], &arr[r]);
        swapNumbers(arr, l + 1, r - 1);
    }
}
void main()
{
    printf("Enter length of array\n");
    int input = 7;
    scanf("%d", &input);
    const int n = input;
    int arr[n];
    printf("Populating array\n");
    for (int i = 0; i < n; i++)
    {
        arr[i] = randInt();
    }
    printf("Entered array is \n");
    printArray(n, arr);
    if (!(n & 1))
    {
        swapNumbers(arr, 0, n - 1);
    }
    else
    {
        swapNumbers(arr, 0, n - 2);
    }
    printf("\nAfter swapping\n");
    printArray(n, arr);
}