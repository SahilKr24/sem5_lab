/*Write a menu driven program as given below, to sort an array of n integers in ascending order by insertion sort algorithm and determine the time required (in terms of step/frequency count) to sort the elements. Repeat the experiment for different values of n and different nature of data (i.e.apply insertion sort algorithm on the data of array that are already sorted, reversly sorted and random data). Finally plot a graph of the time taken versus n for each type of data. The elements can be read from a file or can be generated using the random number generator.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
double insertionsort(int arr[],int n)
{
		clock_t s;
    double t;
		s=clock();
    int key;
    for (int i = 1; i < n; i++)
    {
      key = arr[i];
      int j = i - 1;
      while ( j >= 0 && arr[j] > key)
      {
        arr[j + 1] = arr[j];
        j = j - 1;
      }
      arr[j + 1] = key;
     }
     s=clock()-s;
    t = ((double)s)/CLOCKS_PER_SEC;
   return t;
}
void display(int arr[],int n)
{
    for (int i = 0; i <n; i++)
    {
    	printf("%d ", arr[i]);
    }
    printf("\n");
}

void generate(int arr[],int n)
{
	for(int i=0;i<n;i++)
  arr[i]=rand()%100;
}

void ascensort(int arr[],int n)
{
	for (int i = 0; i < n; ++i)
  {
  	for (int j = i + 1; j < n; ++j)
    {
    	if (arr[i] > arr[j])
      {
      	int a = arr[i];
        arr[i] = arr[j];
        arr[j] = a;
      }
   	}
 }
}

void descsort(int arr[],int n)
{
	for (int i = 0; i < n; ++i)
  {
 		for (int j = i + 1; j < n; ++j)
    {
    	if (arr[i] < arr[j])
      {
      	int a = arr[i];
        arr[i] = arr[j];
       	arr[j] = a;
      }
    }
 	}
}

double algo1(int arr[],int n)
{
    generate(arr,n);
    double x=insertionsort(arr,n);
    return x;
}
double algo2(int arr[],int n)
{
    ascensort(arr,n);
    double x=insertionsort(arr,n);
    return x;
}double algo3(int arr[],int n)
{
    descsort(arr,n);
    double x=insertionsort(arr,n);
    return x;
}

int main()
{
    int ch;
    double n1, n2;
    int n;
    printf("Enter the size of array::");
    scanf("%d",&n);
    int q=0;
    int arr[n];
    double x;
		printf("Enter an option \n 0. Exit \n 1. n Random numbers=>Array \n 2. Display the Array \n 3. Sort the Array in Ascending Order by using Insertion Sort Algorithm \n 4. Sort the Array in Descending Order by using any sorting algorithm \n 5. Time Complexity to sort ascending of random data \n 6. Time Complexity to sort ascending of data already sorted in ascending order \n 7. Time Complexity to sort ascending of data already sorted in descending order \n 8. Time Complexity to sort ascending of data for all Cases (DataAscending, Data in Descending & Random Data) in Tabular form for values n=5000 to 50000, step=5000 \n");
 		while(q!=1)
 		{
    	printf("ENTER YOUR CHOICE\n");
    	scanf(" %d",&ch);
    	switch(ch)
    	{
        case 0: q=1;
            break;
        case 1: generate(arr,n);
            break;
        case 2: display(arr,n);
            break;
        case 3: x=insertionsort(arr,n);
        				display(arr,n);
            break;
        case 4: descsort(arr,n);
        				display(arr,n);
            break;
        case 5: printf("Random Array \n");
            x=algo1(arr,n);
            display(arr,n);
            printf("Step required is %f\n",x);
            break;
        case 6: printf("Ascending Array \n");
        		x=algo2(arr,n);
        		display(arr,n);
            printf("Step required is %f\n",x);
            break;
        case 7: printf("Decending Array \n");
        		x=algo3(arr,n);
        		display(arr,n);
            printf("Step required is %f\n",x);
            break;
        case 8: printf(" Value of n \t Average case(Randomly) \t Best Case(Ascending) \t Worst Case (Descending)\n");
                for(int i=5000;i<50000;i+=5000)
                {
                    int a[i];
                    double p1=algo1(a,i);
                    double p2=algo2(a,i);
                    double p3=algo3(a,i);
                    printf("%d \t\t %f \t\t\t %f \t\t\t\t%f \t",i,p1,p2,p3);
                }
            break;
        default:
            printf("Wrong Input\n");
            break;
    }
 }
    return 0;
}
