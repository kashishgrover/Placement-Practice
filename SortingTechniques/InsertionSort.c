//INSERTION SORT ALGORITHM

//TIME COMPLEXITY:
////BEST - O(n)
////AVERAGE - O(n^2)
////WORST - O(n^2)

//SPACE COMPLEXITY: O(1)

#include <stdio.h>

int inputArray(int[], int);
int insertionSort(int[], int);
int displayArray(int[], int);

int main(void)
{
  int arr[100];
  int n;
  printf("Enter Number of Elements: ");
  scanf("%d", &n);
  inputArray(arr, n);
  insertionSort(arr, n);
  displayArray(arr, n);
}

int inputArray(int *arr, int n)
{
  int i=0;
  printf("Enter Array:\n");
  for(i=0; i<n; i++)
  {
    scanf("%d", &arr[i]);
  }
}

int insertionSort(int *arr, int n)
{
  int temp;
  int i, j;
  for (i=1; i<n; i++)
  {
    temp = arr[i];
    j = i - 1;
    while (temp < arr[j] && j >= 0)
    {
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1] = temp;
  }
}

int displayArray(int *arr, int n)
{
  int i;
  printf("\nSorted Array:");
  for(i=0; i<n; i++)
  {
    printf("\n%d", arr[i]);
  }
  printf("\n");
}