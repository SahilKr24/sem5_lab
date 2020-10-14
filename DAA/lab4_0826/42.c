#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int randInt()
{
    __time_t t;
    srand((unsigned)t * rand());
    return rand() % 5000;
}
int merge(int arr[],int l,int m,int r,int arr2[]){
    int mid = m;

    int n1 = mid - l + 1;
    int n2 = r - mid;

    int L[n1],R[n2];

    for(int i=0;i<n1;i++){
        L[i] = arr[l+i];
    }
    for(int j=0;j<n2;j++){
        R[j] = arr[mid + 1 + j ]; 
    }

    int i=0;
    int j=0;
    int k = l;
    while(i < n1 && j < n2){
        if (L[i] < R[j] ){
            arr2[k] = L[i];
            i++;
        }
        else{
            arr2[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr2[k++] = L[i++];
    }
    while(j<n2){
        arr2[k++] = R[j++];
    }


}
int mergeSort(int arr1[],int l,int r,int arr2[]){
    if (l<r){
        printf("Hi");
        int m = l + (r-1) / 2;
        mergeSort(arr1,l,m,arr2);
        mergeSort(arr1,m+1,r,arr2);
        merge(arr1,l,m,r,arr2);
    }
}

void analyze(){
    int n = 5000;
    int arr[5000];
    int arr2[5000];
    for (int i = 0; i < n; ++i)
    {   int num = randInt();
        arr[i] = num;
    }
    //Average Case Starts Here
    __clock_t t;
    double time_taken; 
    int x,result;
    t = clock();
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    mergeSort(arr,0,n-1,arr2);
    printf("Average case %lf",time_taken);


}

int main(){
    analyze();

}