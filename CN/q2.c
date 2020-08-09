#include <stdio.h>
#include <string.h>

struct Info
{
  int roll_no;
  char name[50];
  float CGPA;
};

void display(struct Info *grade)
{
  printf("Roll: %d\n", grade->roll_no);
  printf("Name: %s\n", grade->name);
  printf("CGPA: %1.2f\n", grade->CGPA);
}

void main()
{
  struct Info grade;
  printf("Enter Name: ");
  scanf("%s", grade.name);
  printf("Enter Roll: ");
  scanf("%d", &grade.roll_no);
  printf("Enter CGPA: ");
  scanf("%f", &grade.CGPA);
  printf("\nDetails\n");
  display(&grade);
}