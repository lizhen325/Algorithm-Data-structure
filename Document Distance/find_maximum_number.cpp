// find maximum number in the array.
#include <iostream>
#include <string>
#include <array>
using namespace std;

int main()
{
	int arr[] = { 1, 2, 7, 4, 5 };
	int temp = 0;
	// length of array
	int length = sizeof(arr) / sizeof(int);
	for (int i = 0; i < length; ++i)
		if (arr[i] > temp)
		{
			temp = arr[i];
		}
	cout << temp << endl;
	system("pause");
	return 0;
}