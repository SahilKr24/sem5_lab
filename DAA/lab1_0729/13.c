#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void EvenOdd(int arr[], int size)
{
	int left = 0, right = size - 1;
	while (left < right)
	{
		while (arr[left] % 2 == 0 && left < right)
			left++;
		while (arr[right] % 2 == 1 && left < right)
			right--;

		if (left < right)
		{
			swap(&arr[left], &arr[right]);
			left++;
			right--;
		}
	}
}

int main()
{
	int size = 0;
	printf("Enter the length of the array: ");
	scanf("%d", &size);

	int arr[size];
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 99;

	printf("The Array :\n");
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");

	EvenOdd(arr, size);

	printf("Array after sorting: \n");
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}
