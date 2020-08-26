#include <stdio.h>

void compute(int number)
{
    int sqrt = number / 2;
    int temp = 0;
    while (sqrt != temp)
    {
        temp = sqrt;
        sqrt = (number / temp + temp) / 2;
    }
    printf("Result: %d\n", sqrt);
}

void main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    compute(n);
}