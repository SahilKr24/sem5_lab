#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n;
  printf("Enter an integer number");
  scanf("%d", &n);

  int a = (n >> 24) & 0xff;
  int b = (n >> 16) & 0xff;
  int c = (n >> 8) & 0xff;
  int d = n & 0xff;

  printf("first byte -> %d\n", a);
  printf("second byte -> %d\n", b);
  printf("third byte -> %d\n", c);
  printf("fourth byte -> %d\n", d);
}