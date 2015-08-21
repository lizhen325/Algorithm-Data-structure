//Quick Sort
//select one of the values, which we call the pivot.
//divide the list into two, such that first part contains all values are smaller than pivot,
//and the second part contains all values are bigger than pivot.
//sort the two parts separately and join the parts

#include <iostream>

using namespace std;

int arr[] = { 7, 2, 9, 4, 5, 6, 0, 8 };

void quick_sort(int first, int last)
{
	int temp;
	int i = first + 1;
	int j = last;
	int pivot = arr[first];
	while (i < j)
	{
		while ((arr[i] < pivot) && (i < last)) { i++; }
		while (arr[j] > pivot) { j--; }
		if (i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
		if (pivot > arr[j])
		{
			temp = arr[first];
			arr[first] = arr[j];
			arr[j] = temp;
		}
	
	if (first < j - 1) quick_sort(first, j - 1);
	if (j + 1 < last) quick_sort(j + 1, last);
}

int main()
{

	int n = sizeof(arr) / sizeof(int);
	quick_sort(0, n-1);
	for (int i = 0; i < n; ++i)
		cout << arr[i];
	system("pause");
	return 0;
}
