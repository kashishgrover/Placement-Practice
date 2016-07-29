/*
Factorial(n):

* Create an array 'res[]' of MAX size where MAX is the number of digits in a factorial
* Initialize res[] = 1 and sizeof(res) = res_size = 1
* Do following for all numbers from x = 2 to n.
  -> Multiply x with res[] and update res[] and res_size to store the multiplication result.

Multiply(res[], x):

1) Initialize carry as 0.
2) Do following for i = 0 to res_size – 1
….a) Find value of res[i] * x + carry. Let this value be prod.
….b) Update res[i] by storing last digit of prod in it.
….c) Update carry by storing remaining digits in carry.
3) Put all digits of carry in res[] and increase res_size by number of digits in carry.


Example to show working of multiply(res[], x):

A number 5189 is stored in res[] as following -

res[] = {9, 8, 1, 5}
x = 10

Initialize carry = 0;

i = 0, prod = res[0]*x + carry = 9*10 + 0 = 90.
res[0] = 0, carry = 9

i = 1, prod = res[1]*x + carry = 8*10 + 9 = 89
res[1] = 9, carry = 8

i = 2, prod = res[2]*x + carry = 1*10 + 8 = 18
res[2] = 8, carry = 1

i = 3, prod = res[3]*x + carry = 5*10 + 1 = 51
res[3] = 1, carry = 5

res[4] = carry = 5

res[] = {0, 9, 8, 1, 5} 


*/

#include "stdio.h"
#define MAX 500 //Maximum number of digits in the output

int multiply(int x, int res[], int res_size);

// This function finds factorial of large numbers and prints them
void factorial(int n)
{
	int res[MAX]; 
	// Initialize result
	res[0] = 1;
	int res_size = 1; 
	// Apply simple factorial formula n! = 1 * 2 * 3 * 4 * ... * n
	int i;
	for (i=2; i<=n; i++)
	    res_size = multiply(i, res, res_size);

	printf("Factorial of entered number is: \n");
	for (i = res_size-1; i>=0; i--)
	    printf("%d",res[i]);
}

// This function multiplies x with the number represented by res[].
// res_size is size of res[] or number of digits in the number represented
// by res[]. This function uses simple school mathematics for multiplication.
// This function may value of res_size and returns the new value of res_size
int multiply(int x, int res[], int res_size)
{
    int carry = 0;  // Initialize carry
 	int i;
    // One by one multiply n with individual digits of res[]
    for (i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;  // Store last digit of 'prod' in res[]
        carry  = prod/10;    // Put rest in carry
    }
 
    // Put carry in res and increase result size
    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

// Driver function
int main()
{
	int num;
	printf("Enter a number - ");
	scanf("%d", &num);
    factorial(num);
    printf("\n");
    return 0;
}