#include <stdio.h>
#include <stdlib.h>

struct pkt{
  char ch1;
  char ch2[2];
  char ch3;
};

void display(struct pkt *n)
{
  printf("Contents of the structure: ");
  printf("%c %c %c %c \n",n->ch1,n->ch2[0],n->ch2[1],n->ch3);
}

int main()
{
  int n;
  printf("Enter an integer number");
  scanf("%d", &n);

  struct pkt num;
  num.ch1 = (n >> 24) & 0xff;
  num.ch2[0] = (n >> 16) & 0xff;
  num.ch2[1] = (n >> 8) & 0xff;
  num.ch3 = n & 0xff;

  display(&num);

  unsigned int a = num.ch3;
  unsigned int b = num.ch2[1];
  unsigned int c = num.ch2[0];
  unsigned int d = num.ch1;

  printf("0x%X\n",(((d<<24) & 0xff000000) | ((c<<16) &0x00ff0000) | ((b<<8) & 0x0000ff00) | (a) & 0x000000ff));
}