//selection sort
//find the smallest value then swap with the front

#include <iostream>

using namespace std;

int main()
{
	int arr[] = { 7, 2, 9, 4, 5, 6, 0, 8 };
	int temp;
	int min;
	int n = sizeof(arr) / sizeof(int);
	for (int i = 0; i < n - 1; ++i)
	{
		min = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
	for (int i = 0; i < n; ++i)
		cout << arr[i] << ",";
	system("pause");
	return 0;
}