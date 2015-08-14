//complexity is O(n^2)
#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace std;

int main()
{
	int arr[] = { 5, 1, 6, 2, 4, 3 };
	// length of array
	int length = sizeof(arr) / sizeof(0);
	int i, j, key;
	//loop start from the second value
	for (i = 1; i < length; i++)
	{
		key = arr[i];
		j = i - 1;
		// loop start from the first value
		while (j >= 0 && key < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;

		}
		arr[j + 1] = key;
	}
	for (int i = 0; i < length; ++i)
		cout << arr[i];
	system("pause");
	return 0;
}