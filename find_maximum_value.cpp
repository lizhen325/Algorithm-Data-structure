#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

int main()
{
	// finding the maximum value in array
	int arr[] = { 31, 41, 59, 26, 411, 58 };
	int maximum = arr[0];
	//length of array
	int length = sizeof(arr) / sizeof(0);
	for (int i = 1; i < length; ++i)
	{
		if (arr[i] > maximum)
			maximum = arr[i];
	}
	cout << maximum;
	system("pause");
	return 0;
}