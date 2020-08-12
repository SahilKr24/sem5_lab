#include <stdio.h>
#include <stdlib.h>

int duplicates(int arr[], int length){
  int count = 0,i,j;
  for (i = 0; i < length; i++)
	{
		for(j = i + 1; j < length; j++)
		{
    		if(arr[i] == arr[j])
    		{
    			count++;
				break;
			}
		}
	}
  return count;
}

int mostOccurance(int arr[], int n)
{
    int max_freq = 0;
    int ans = -1;
    for (int i = 0;i<=n-1;i++)
    {
        int curr_freq = 1;
        for (int j = i+1;j<=n-1;j++)
            if (arr[j] == arr[i])
                curr_freq = curr_freq + 1;
        
        if (max_freq < curr_freq)
        {
            max_freq = curr_freq;
            ans = arr[i];
        }
       else if (max_freq == curr_freq)
          ans = ans<arr[i]?ans:arr[i];
    }
   return ans;
}

int main()
{
  int length = 0;
  printf("Enter the length of the array: ");
  scanf("%d", &length);
  int arr[length];
  for (int i = 0; i < length; i++)
  {
    arr[i] = rand() % 5;
  }
  printf("The Array :\n");
  for (int i = 0; i < length; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
  printf("No of duplicate elememts: %d \n",duplicates(arr,length));
   printf("Most repeating elememts: %d \n",mostOccurance(arr,length));
  return 0;
}