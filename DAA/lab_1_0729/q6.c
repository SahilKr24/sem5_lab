#include<stdlib.h>
#include<stdio.h>
#include<math.h>

void insertionSort(int *p, int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = *(p+i); 
        j = i - 1; 
        while (j >= 0 && *(p+j) > key) { 
            *(p+j+1) = *(p+j); 
            j = j - 1; 
        } 
        *(p+j+1) = key; 
    } 
}

void main(){
    int n,i;
	printf("Enter Number of Elements : ");
	scanf("%d",&n);
	int *p = (int *)calloc(n,sizeof(int));

    for(i=0;i<n;i++){
        *(p+i) = rand() % 100;
	}
    printf("Your Array: ");
	for(i=0;i<n;i++){
        printf("%d ",*(p+i));  
	}
    insertionSort(p, n);
    printf("\nSecond Largest: %d\n", *(p+n-2));
    printf("Second Smallest: %d\n", *(p+1));
}