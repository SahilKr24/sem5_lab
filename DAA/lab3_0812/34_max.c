#include <stdio.h>
#include <stdlib.h>
int findMax(int arr[], int n)
{   int max = 0;
    for(int i=0;i<n;++i){
        int sum = 0;
        for(int j=i;j<n;++j){
            sum+=arr[j];
            if(sum > max){
                max = sum;
            }
        }
    }

    return max;
}

int main()
{
    int A[] = {1, 5, 7, -6, 1, -5, -9, -2, -4, 6, 2};
    int max = 0;
    int n = sizeof(A) / sizeof(int);

    max = findMax(A, n);
    for(int i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");
    printf("Max subarray is %d\n", max);
}