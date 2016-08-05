#include <iostream>

using namespace std;

int main()
{
	int key, i, flag = 0;
	int arr[] = {41, 42, 53, 84, 445, 1546, 1757, 1800, 1971, 1990, 2000, 12000, 13000};

	cout << "\t\t\t**Binary Search**\n\n";
	cout << "Following is the array:\n";

	for (i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		cout << i << ")\t" << arr[i] << endl;
	}

	cout << "\nEnter the element to be found - ";
	cin >> key;

	int low = 0, high = sizeof(arr) / sizeof(int);
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == arr[mid])
		{
			flag = 1;
			cout << "Element found at position " << mid + 1 << "!";
		}
		if (key < arr[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}

	if (flag == 0)
		cout << "Element dows not exist!";

	return 0;
}
