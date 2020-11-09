#include <stdio.h>
#include <math.h>

float M[4][4];
float floatA[5][5];
float sum_row[5];
float sum_col[5];
float A[5][5];
int n;
void display(){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.1f\t",A[i][j]);
        }
        printf("\n");
    }
}
void FloatSum(){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            floatA[i][j]=A[i][j]-(int)A[i][j];
        }
    }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum_row[i]=(sum_row[i]+floatA[i][j]);
            }
            sum_row[i]=round(sum_row[i]);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum_col[i]=(sum_col[i]+floatA[j][i]);
            }
            sum_col[i]=round(sum_col[i]);
        }
}
void algo(){
    printf("\n");
    for(int w=0;w<n;w++){
        for(int q=0;q<n;q++){
            if(sum_col[q]>0 && sum_row[w]>0){
                A[w][q]=ceil(A[w][q]);
                sum_col[q]=sum_col[q]-1;
                sum_row[w]=sum_row[w]-1;
            }
            else A[w][q]=floor(A[w][q]);
        }
    }
}
void main(){
    
    printf("\nEnter the size of Matrix upto 5x5\n");
    scanf("%d",&n);
    printf("Enter The values of array (rows followed by columns)\n");
    for(int i=0;i<n;i++){
        for (int j = 0; j < n; j++)
        {
            scanf("%f",&A[i][j]);
        }
    }
    printf("\nEntered Matrix\n");
    display();
    FloatSum();
    algo();
    printf("\nAfter Round off\n");
    display();
}