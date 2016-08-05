#include <iostream>

using namespace std;

int main()
{
	int arr[10], key, flag = 0, i;

	cout << "\t\t\t**Linear Search**\n\n";
	cout << "Enter 10 elements:\n";
	for (i = 0; i < 10; i++)
		cin >> arr[i];

	cout << "\nEnter the element to be found - ";
	cin >> key;

	for (i = 0; i < 10; i++)
		if (key == arr[i])
		{
			cout << "Element found at position " << i + 1 << "!\n";
			flag = 1;
		}

	if (flag == 0)
		cout << "Element dows not exist!";

	return 0;
}
