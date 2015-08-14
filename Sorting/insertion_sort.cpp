#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace std;

void merge_sort(int arr[], int start_index, int length)
{
	int j, k;
	for (start_index; start_index < length; start_index++){
		k = arr[start_index];
		j = start_index - 1;
		while (j >= 0 && k < arr[j]){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = k;
	}
	for (int i = 0; i < length; ++i)
		cout << arr[i];
}

int main()
{
	int arr[] = { 2, 3, 4, 1, 5 };
	int length = sizeof(arr) / sizeof(0);
	merge_sort(arr, 1, length);
	system("pause");
	return 0;
}