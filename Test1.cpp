#include <iostream>
#include <stdio.h>

using namespace std;

int convertToInt(char[]);
int getMatrix();
int findResult();
int printResult();

int main()
{
	char string1[100];
	scanf("%s", string);
	char stringmat[100][100];
	char nstring[10];
	int i;
	for (i = 0; string[i] != ' '; i++)
	{
		nstring[i] = string[i];
	}
	nstring[i + 1] = '\0';	
	convertToInt(nstring);
	for (; string[i] != '\0'; i++)
	{
		findInMatrix(string[i]);
	}
	return -1;
}

/*
3 apple
abc
plz
exy
*/
