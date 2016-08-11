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
	fgets(string1, 100, stdin);

	int found;

	char stringmat[100][100];

	char nstring[10];
	int i, j, k;

	for (i = 0; string1[i] != '\0'; i++)
	{
		nstring[i] = string1[i];
		if (string1[i] == ' ')
			break;
	}

	nstring[i + 1] = '\0';

	int num = convertToInt(nstring);

	for (j = 0; j < num; j++)
	{
		fgets(stringmat[j], 100, stdin);
	}

	for (i++; string1[i] != '\0'; i++)
	{

		for (j = 0; j < num; j++)
		{
			for (k = 0; k < num; k++)
			{
				if (string1[i] == stringmat[j][k])
				{
					found = 1;
					cout << "Found " << string1[i] << " at (" << j << ", " << k << ")\n";
					break;
				}
				else
					found = 0;
			}
			if (found)
				break;
		}
		if (found != 1)
			break;
	}
	if (found)
		cout << "\nFound Word";
	else cout << "Not Found!";
}

int convertToInt(char* a)
{
	return (a[0] - '0');
}

int getMatrix()
{
	return -1;
}

int findResult()
{
	return -1;
}

int printResult()
{
	return -1;
}

int findInMatrix(char a)
{
	return -1;
}

/*
3 apple
abc
plz
exy
*/
