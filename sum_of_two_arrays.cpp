//Consider the problem of adding two n-bit binary intergers. stored in two n-element arrays A and B.
//The sum of the two integers should be stored in binary from in a array C
#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

int main()
{
	int arr1[] = { 6, 7, 8, 9, 10};
	int arr2[] = { 1, 2, 3, 4, 5, 12 };
	//create a new array
	int *arr3 = new int[10];
	//length of array1
	int length_of_arr1 = sizeof(arr1) / sizeof(0);
	//length of arr2
	int length_of_arr2 = sizeof(arr2) / sizeof(0);
	// if length of arr1 greater than and eaqaul to length of array2
	if (length_of_arr1 >= length_of_arr2)
	{

		for (int i = 0; i < length_of_arr2; i++)
		{
			arr3[i] = arr1[i] + arr2[i];
			cout << arr3[i] << ",";
		}
		for (int i = 0; i < length_of_arr1 - length_of_arr2; ++i){
			arr3[length_of_arr2 + 1 + i] = arr1[length_of_arr1 - 1 - i];
				cout << arr3[length_of_arr2 + 1 + i] << ",";
		}
	}
	// if length of arr1 smaller than length of arr2
	else if (length_of_arr1 < length_of_arr2)
	{

		for (int i = 0; i < length_of_arr1; i++)
		{
			arr3[i] = arr1[i] + arr2[i];
			cout << arr3[i] << ",";
		}
		for (int i = 0; i < length_of_arr2 - length_of_arr1; ++i){
			arr3[length_of_arr1 + 1 + i] = arr2[length_of_arr2 - 1 - i];
			cout << arr3[length_of_arr1 + 1 + i] << ",";
		}
	}
	system("pause");
	return 0;
}