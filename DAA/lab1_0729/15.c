#include<stdio.h>
#include<stdlib.h>

void countZeros(int n,int arr[][n]){
    int zeros = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(arr[i][j] == 0){
                ++zeros;
            }
        }

    }

    printf("Number of zeros = %d\n",zeros);
    
}

void sumLeading(int n,int arr[][n]){
    int sum = 0;
    for(int i = 0;i<n;++i){
        for(int j=i+1;j<n;++j){
            sum+=arr[i][j];
        }
    }

    printf("Sum of elements above leading diagonal = %d\n",sum);
}

void showBelowMinorDiagonal(int n,int arr[][n]){
    printf("Elements below minor diagonal are \n");
    for(int i=1;i<n;++i){
        for(int j=0;j<i;++j){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

void diagonalProduct(int n,int arr[][n]){
    int product = 1;
    for (int i = 0; i < n; i++)
    {
        product*=arr[i][i];
    }

    printf("Product of diagonal elements = %d\n",product);
    
}

int main(){
    printf("Enter order of the array\n");
    int input;
    scanf("%d",&input);
    const int n = input;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           printf("Enter arr[%d][%d]\n",i,j);
           scanf("%d",&arr[i][j]);
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    countZeros(n,arr);
    sumLeading(n,arr);
    showBelowMinorDiagonal(n,arr);
    diagonalProduct(n,arr);
    
}