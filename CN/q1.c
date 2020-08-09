#include <stdio.h>

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void main()
{
  int a, b;
  printf("Enter 2 Numbers:\n");
  scanf("%d%d", &a, &b);
  printf("a= %d\nb= %d\n", a, b);
  printf("After Swapping\n");
  swap(&a, &b);
  printf("a= %d\nb= %d\n", a, b);
}