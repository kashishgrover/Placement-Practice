#include <stdio.h>

int isPrime(int n)
{
    int i;
    if (n <= 1)  return 0;
    for (i=2;i*i<n;i++)
        if (n%i == 0)
            return 0; 
    return 1;
}

int main()
{
    int num;
    printf("Enter a number - ");
    scanf("%d",&num);
    isPrime(num) ? printf("Prime\n") : printf("Not Prime\n");
}