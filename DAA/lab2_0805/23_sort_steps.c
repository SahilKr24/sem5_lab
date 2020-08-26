#include <stdio.h>
#include <stdlib.h>

int randInt()
{
    __time_t t;
    srand((unsigned)t * rand());
    return rand() % 50;
}

long insertionSort(int arr[], int n)
{
    long count = 1;
    for (int j = 1; j < n; ++j, count++)
    {
        count++; //number of times temp is assigned
        int temp = arr[j];
        count++; //number of times i is assigned
        int i = j - 1;
        count++; //number of times while loop is initialized
        while (arr[i] > temp && i >= 0)
        {
            count++; //number of shift operations
            arr[i + 1] = arr[i];
            count++; //number of i decrements
            i--;
        }
        count++; // number of times temp is assigned to it's position
        arr[i + 1] = temp;
    }
    return count;
}

long insertionSortDescending(int arr[], int n)
{
    long count = 1;
    for (int j = 1; j < n; ++j, count++)
    {
        count++; //number of times temp is assigned
        int temp = arr[j];
        count++; //number of times i is assigned
        int i = j - 1;
        count++; //number of times while loop is initialized
        while (arr[i] < temp && i >= 0)
        {
            count++; //number of shift operations
            arr[i + 1] = arr[i];
            count++; //number of i decrements
            i--;
        }
        count++; // number of times temp is assigned to it's position
        arr[i + 1] = temp;
    }
    return count;
}

void analyze(int n){
    int *arr1 = malloc(n*sizeof(int)),*arr2 = malloc(n*sizeof(int)),*arr3 = malloc(n*sizeof(int)); //for ascending, descending and random respectively
    for (int i = 0; i < n; ++i)
    {   int num = randInt();
        arr1[i] = num;
        arr2[i] = num;
        arr3[i] = num;
    }
    insertionSort(arr1,n); //sort data in ascending order
    insertionSortDescending(arr2,n); //sort data in descending order
    
    long count1 = insertionSort(arr1,n); //count steps for sorting already ascending sorted data;
    long count2 = insertionSort(arr2,n); //count steps for sorting descending sorted data;
    long count3 = insertionSort(arr3,n); //count steps for sorting random data

    printf("%5d\t%5d\t%10ld\t%10ld\t%10ld",n/5000,n,count1,count2,count3);
}


void main()
{
    int *arr;
    int n;
    int ch = 0;
    long count = 0;

    do
    {
        printf("Select an option\n");
        printf("\
            0. Quit\n\
            1. n Random numbers=>Array\n\
            2. Display the Array\n\
            3. Sort the Array in Ascending Order by using Insertion Sort Algorithm\n\
            4. Sort the Array in Descending Order by using any sorting algorithm\n\
            5. Time Complexity to sort ascending of random data\n\
            6. Time Complexity to sort ascending of data already sorted in ascending order\n\
            7. Time Complexity to sort ascending of data already sorted in descending order\n\
            8. Time Complexity to sort ascending of data for all Cases (Data Ascending, Data in Descending & Random Data) in Tabular form for values n=5000 to 50000, step=5000\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            break;
        case 1:
        {
            printf("Enter length of array\n");
            scanf("%d",&n);

            arr = malloc(n * sizeof(int));
            for (int i = 0; i < n; ++i)
            {
                arr[i] = randInt();
            }
            break;
        }
        case 2:{
            printf("The array is \n");
            for(int i=0;i<n;++i){
                printf("%d ",arr[i]);
            }
            printf("\n");
            break;
        }
        case 3:{
            count = insertionSort(arr,n);
            printf("Array of length %d sorted in %ld steps \n",n,count);
            printf("Array after sorting is \n");
            for(int i=0;i<n;++i){
                printf("%d ",arr[i]);
            }
            printf("\n");
            break;
        }
        case 4:{
            insertionSortDescending(arr,n);
            printf("Array after sorting is \n");
            for(int i=0;i<n;++i){
                printf("%d ",arr[i]);
            }
            printf("\n");
            break;
        }
        case 5:{
            count = insertionSort(arr,n);
            printf("Array of length %d sorted in %ld steps \n",n,count);
            break;
        }
        case 6:{
            insertionSort(arr,n);
            count = insertionSort(arr,n);
            printf("An already sorted array was sorted in %ld steps\n",count);
            break;
        }
        case 7:{
            insertionSortDescending(arr,n);
            count = insertionSort(arr,n);
            printf("An array sorted in descending order was sorted in %ld steps\n",count);
        }
        case 8:{
            printf("S.No\tVal N\tData in Asc\tData in Desc\tRandom Data\n");
            for(int i=5000;i<=50000;i+=5000){
                analyze(i);
                printf("\n");
            }
            break;
        }
        }
    } while (ch != 0);
}