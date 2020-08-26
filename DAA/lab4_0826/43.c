/* C implementation QuickSort */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randInt()
{
  __time_t t;
  srand((unsigned)t * rand());
  return rand() % 1000;
}

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

void printArray(int arr[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void analyse(int n)
{

  int *arr = malloc(n * sizeof(int));
  for (int i = 0; i < n; ++i)
  {
    int num = randInt();
    arr[i] = num;
  }

  int temp, i, j;
  clock_t t;
  double rt, at, dt;

  t = clock();
  quickSort(arr, 0, n - 1);
  t = clock() - t;
  rt = ((double)t) / CLOCKS_PER_SEC;

  t = clock();
  quickSort(arr, 0, n - 1);
  t = clock() - t;
  at = ((double)t) / CLOCKS_PER_SEC;

  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - i - 1; j++)
      if (arr[j] < arr[j + 1])
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }

  t = clock();
  quickSort(arr, 0, n - 1);
  t = clock() - t;
  dt = ((double)t) / CLOCKS_PER_SEC;
  printf("%d\t%5d\t%10f\t%10f\t%10f", n / 5000, n, at, dt, rt);
}

int main()
{
   printf("S.No\tVal N\t  Asc Case\t  Desc Case\t Random Data\n\n");
  for (int i = 5000; i <= 50000; i += 5000)
  {
    analyse(i);
    printf("\n");
  }
}