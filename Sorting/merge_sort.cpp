#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
using namespace std;

void merge(int* input, int p, int r)
{
	// medium value
	int mid = (p + r) / 2;
	int i1 = 0;
	//first of array. ex arr[] = {1,2,3} points 1.
	int i2 = p;
	//half of array ex arr[1,2,3,4,5,6] points 4
	int i3 = mid + 1;

	// new array with length of r called temp
	int *temp = new int[r];

	// Merge in sorted form the 2 arrays
	while (i2 <= mid && i3 <= r){
		if (input[i2] < input[i3])
			temp[i1++] = input[i2++];
		else
			temp[i1++] = input[i3++];
		}
	// Merge the elements in left array
	while (i2 <= mid)
		temp[i1++] = input[i2++];

	// Merge elements in right array
	while (i3 <= r)
		temp[i1++] = input[i3++];

	// Move from temp array
	for (int i = p; i <= r; i++)
		input[i] = temp[i - p];
}

void merge_sort(int* input, int p, int r)
{
	if (p < r)
	{
		int mid = (p + r) / 2;
		// first recursion merge elements left array
		merge_sort(input, p, mid);
		// second recursion merge elements right array
		merge_sort(input, mid + 1, r);
		// merge
		merge(input, p, r);
	}
}

int main()
{
	int a[] = { 500, 700, 800, 100, 300, 200, 900, 400, 1000, 600 };
	cout << "Input: ";
	int n = sizeof(a) / sizeof(0);
	for (int i = 0; i < n; ++i)
		cout << a[i] << " , ";
	cout << endl;
	merge_sort(a, 0, n);
	cout << "Output: ";
	for (int i = 0; i < n; ++i)
		cout << a[i+1] << " , ";
	cout << endl;
	system("pause");
	return 0;
}