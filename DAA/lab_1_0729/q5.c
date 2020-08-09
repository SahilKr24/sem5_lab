#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int nonZero(int *p, int c, int r){
    int count = 0;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(*(p + i*c + j) != 0)
                count++;
    return count;
}

int sumDiag(int *p, int c, int r){
    int sum = 0;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(i < j)
                sum+=*(p + i*c + j);
    return sum;
}

int prodDiag(int *p, int c, int r){
    int prod = 1;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(i==j)
                prod *= *(p + i*c + j);
    return prod;
}

void belowMinorDiag(int *p, int c, int r){
    printf("Elements below minor diag: \n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if ((i+j)>=c)
                printf("%d  ", *(p + i*c + j));
            else
                printf("**  ");
        }
        printf("\n");
    }
}

void main() {
    int dim,c,r;
    printf("Enter size of sq. matrix: ");
    scanf("%d", &dim);
    c=r=dim;
    int *p = (int *)malloc(c*r*sizeof(int));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            *(p + i*c + j) = rand()%100;
        }
    }
    printf("Your Matrix: \n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d  ", *(p + i*c + j));
        }
        printf("\n");
    }

    printf("\nNon Zero Elements: %d\n\n", nonZero(p, c, r));
    printf("Sum of Elements above Leading Diagonal: %d\n\n", sumDiag(p, c, r));
    belowMinorDiag(p, c, r);
    printf("\nProduct of Diagonal Elements: %d\n", prodDiag(p, c, r));
}