#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randInt(int n)
{
  __time_t t;
  srand((unsigned)t * rand());
  return rand() % n;
}

void insertionSort(int arr[], int n, int p)
{
  for (int j = 1; j < n; ++j)
  {
    int temp = arr[j];
    int i = j - 1;
    while (arr[i] > temp && i >= 0)
    {
      arr[i + 1] = arr[i];
      i--;
    }
    arr[i + 1] = temp;
  }
  if (p == 1)
  {
    for (int i = 0; i < n; ++i)
    {
      printf("%d ", arr[i]);
    }
    printf("\n");
  }
}

int binarySearch(int arr[], int l, int r, int x)
{
  if (r >= l)
  {
    int mid = l + (r - l) / 2;

    if (arr[mid] == x)
    {
      return mid;
    }

    if (arr[mid] > x)
      return binarySearch(arr, l, mid - 1, x);

    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}

void analyse(int n)
{
  int *arr = malloc(n * sizeof(int));
  for (int i = 0; i < n; ++i)
  {
    arr[i] = i;
  }

  clock_t t;
  double time_taken;
  int x, result;

  t = clock();
  x = arr[randInt(n)];
  result = binarySearch(arr, 0, n - 1, x);
  t = clock() - t;
  time_taken = ((double)t) / CLOCKS_PER_SEC;
  double count1 = time_taken;

  t = clock();
  x = arr[n / 2];
  result = binarySearch(arr, 0, n - 1, x);
  t = clock() - t;
  time_taken = ((double)t) / CLOCKS_PER_SEC;
  double count2 = time_taken;

  t = clock();
  x = arr[0];
  result = binarySearch(arr, 0, n - 1, x);
  t = clock() - t;
  time_taken = ((double)t) / CLOCKS_PER_SEC;
  double count3 = time_taken;

  printf("%f %f %f \n", count1, count2, count3);
}

int main(void)
{
  printf("avg\t best\t   worst\n");
  for (int i = 5001; i <= 50001; i += 5000)
  {
    analyse(i);
  }
  return 0;
}