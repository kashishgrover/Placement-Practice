#include <stdio.h>

unsigned long getFactorial(int num)
{
	int i;
	unsigned long fact = 1;
	for (i=1;i<=num;i++)
	{
		fact = fact * i;
	}
	return fact;
}

int main(void)
{
	int num;
	printf("Enter a number - ");
	scanf("%d", &num);
	unsigned long fact = getFactorial(num);
	printf("Factorial = %lu\n",fact);
}

//NOTE:
//INT will be successful till only 12.
//UNSIGNED LONG will be successful till 20.
//We need a better way to calculate for bigger numbers!