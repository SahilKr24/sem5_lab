#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n;
  printf("Enter an integer number");
  scanf("%d", &n);

  unsigned int a = (n >> 24) & 0xff;
  unsigned int b = (n >> 16) & 0xff;
  unsigned int c = (n >> 8) & 0xff;
  unsigned int d = n & 0xff;

  printf("first byte -> %X\n", a);
  printf("second byte -> %X\n", b);
  printf("third byte -> %X\n", c);
  printf("fourth byte -> %X\n", d);
}