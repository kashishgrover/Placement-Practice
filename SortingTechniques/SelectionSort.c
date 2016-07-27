#include <stdio.h>

int inputArray(int[], int);
int selectionSort(int[], int);
int displayArray(int[], int);

int main(void)
{
  int arr[100];
  int n;
  printf("Enter Number of Elements: ");
  scanf("%d", &n);
  inputArray(arr, n);
  selectionSort(arr, n);
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

int selectionSort(int *arr, int n)
{
  int i, j;
  int temp;
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(arr[i]>arr[j])
      {
       temp=arr[i];
       arr[i]=arr[j];
       arr[j]=temp;
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