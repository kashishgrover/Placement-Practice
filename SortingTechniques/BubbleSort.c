//BUBBLE SORT ALGORITHM

//TIME COMPLEXITY:
////BEST - O(n)
////AVERAGE - O(n^2)
////WORST - O(n^2)

//SPACE COMPLEXITY: O(1)

#include <stdio.h>

int inputArray(int[], int);
int bubbleSort(int[], int);
int displayArray(int[], int);

int main(void)
{
  int arr[100];
  int n;
  printf("Enter Number of Elements: ");
  scanf("%d", &n);
  inputArray(arr, n);
  bubbleSort(arr, n);
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

int bubbleSort(int *arr, int n)
{
  int i, j;
  int temp;
  for(i=0;i<(n-1);i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(arr[j]<arr[j+1])
      {
       temp=arr[j];
       arr[j]=arr[j+1];
       arr[j+1]=temp;
      }
    }
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