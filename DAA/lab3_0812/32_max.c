#include<stdio.h>
#include<stdlib.h>

int randInt()
{
    __time_t t;
    srand((unsigned)t * rand());
    return rand() % 50;
}

int findMax(int arr[],int n){
    int max = 0;
    for(int i=0;i<n;++i){
        if (max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

void main(){
    int arr[] = {1,2,3,4,2,2,6,2,2};
    int n = 9;
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n",i,arr[i]);
    }
    
    printf("O(n^2) approach\n");
    for(int i=0;i<n;++i){
        int num = arr[i];
        int count = 0;
        for(int j=i+1;j<n;++j){
            if(num == arr[j]){
                count++;
            }
        }
        if(count>=n/2){
            printf("%d occurrs more than n/2 times\n",num);
        }
    }

    int max = findMax(arr,n);

    int b[max];

    for(int i=0;i<max;++i){
        b[i] = 0;
    }

    for(int i=0;i<n;++i){
        int num = arr[i];
        int count = 0;
        b[num]++;
    }

    printf("O(n) approach\n");
    for(int i=0;i<max;++i){
        if(b[i] > n/2){
            printf("%d was repeated more than n/2 times\n",i);
        }
    }
}