
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void rearrange(int *p, int n){
    int temp;
    if(n%2!=0)
        temp = *(p+n-1);
    for(int i=0;i<n;i+=2){
        swap((p+i), (p+i+1));
    }
    *(p+n-1) = temp;
}

void main(){
    int n,i;
	printf("Enter Number of Elements : ");
	scanf("%d",&n);
	int *p = (int *)calloc(n,sizeof(int));

    for(i=0;i<n;i++){
        *(p+i) = rand() % 100;
	}
    printf("Before Rearranging: ");
	for(i=0;i<n;i++){
        printf("%d ",*(p+i));  
	}

    rearrange(p, n);

    printf("\nAfter Rearranging: ");
	for(i=0;i<n;i++){
        printf("%d ",*(p+i));  
	}
    printf("\n");
}