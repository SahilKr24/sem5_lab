#include <stdio.h>
#include <stdlib.h>

unsigned int switchEndian(unsigned int x)
{
	return (((x>>24) & 0x000000ff) | ((x>>8) & 0x0000ff00) | ((x<<8) & 0x00ff0000) | ((x<<24) & 0xff000000));
}

int main()
{
  unsigned int i = 0x010203AB;
  int *k = &i;
  if (*k == 0xAB)
    printf("Architecture is LITTLE ENDIAN\n");
  else
    printf("Architecture is BIG ENDIAN\n");
  printf("Enter a number: ");
  int num;
  scanf("%d",&num);
  int littleEndian = num ;
	printf("\nBig Endian    = 0x%X\n",littleEndian);
	printf("Little Endian = 0x%X\n",switchEndian(littleEndian));
}