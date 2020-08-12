#include<stdio.h>
#include<stdlib.h>

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

int calcProduct(int arr[],int l,int r){
    if(l<r){
        return arr[l] * arr[r] * calcProduct(arr,l+1,r-1);
    }
    else if (l == r){
        return arr[l];
    }
    else
        return 1;
}
void findProduct(int n,int index,int arr[n]){
    if(index == n){
        return ;
    }
    int productl = calcProduct(arr,0,index-1);
    int productr = calcProduct(arr,index+1,n-1);
    int temp = productl * productr;
    findProduct(n,index+1,arr);
    arr[index] = temp;
}

int main(){
    printf("Enter length of array\n");
    int input;
    scanf("%d", &input);
    const int n = input;
    int arr[n];
    printf("Entering array\n");
    for (int i = 0; i < n; i++)
    {
        arr[i] = randInt();
    }
    printf("Entered array is \n");
    printArray(n, arr);
    findProduct(n,0,arr);
    printf("\nproducts\n");
    printArray(n,arr);
    printf("\n");
}