#include <stdio.h>
#include <stdlib.h>

int main()
{
  unsigned int i = 0x101213AB;
  int *k = &i;
  if (*k == 0xAB)
  {
    printf("\n Architecture is LITTLE ENDIAN\n");
  }
  else
  {
    printf("\n Architecture is BIG ENDIAN\n");
  }
}