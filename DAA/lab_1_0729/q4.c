#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void rotate(int *a, int *b, int *c){
    swap(a,c);
    swap(b,c);
}

void main(){
    int a,b,c;
    printf("Enter 3 integers: ");
    scanf("%d%d%d", &a, &b, &c);
    printf("Before Rotation:\n a = %d\n b = %d\n c = %d\n", a, b, c);
    rotate(&a, &b, &c);
    printf("After Rotation:\n a = %d\n b = %d\n c = %d\n", a, b, c);
}