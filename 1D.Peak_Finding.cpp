//1D Peak Finding
//Objective
//Given an array A with n elements, ﬁnd the index i of the peak element A[i] where A[i] ≥ A[i − 1]
//and A[i] ≥ A[i + 1].For elements on the boundaries of the array, the element only needs to be
//greater than or equal to its lone neighbor to be considered a peak.Or, say A[−1] = A[n] = ∞.

//Algorithm
//Given an array A with n elements :
//• Take the middle element of A, A[n/2], and compare that element to its neighbors

//• If the middle element is greater than or equal to its neighbors, then by deﬁnition, that element
//is a peak element.Return its index n/2.

//• Else, if the element to the left is greater than the middle element, then recurse and use this
//algorithm on the left half of the array, not including the middle element.

//• Else, the element to the right must be greater than the middle element.Recurse and use this
//algorithm on the right half of the array, not including the middle element.
#include <iostream>
using namespace std;

int main()
{
	int arr[] = { 1, 4, 5, 7, 4, 3, 1 };
	int i = 0;
	int j = 1;
	//length of array n
	int n = sizeof(arr) / sizeof(arr[0]);
	if (arr[n / 2] < arr[n / 2 - 1])
	{
		cout << "look at left half from 1 to n/2-1 to look for a peak" << endl;
		for (int i = 0, j = 1; i < (n / 2 - 1); ++i, ++j){
			if ((arr[j] >= arr[i]) && (arr[j] >= arr[j + 1]))
			{
				cout << "the peak number is : " << arr[j] << endl;
			}
		}
				
	}

	else if (arr[n / 2] < arr[n / 2 + 1]){
		cout << "look at n/2+1 to n for a peak" << endl;
		for (int i = n/2, j = i + 1; i < n; ++i, ++j){
			if ((arr[j] >= arr[i]) && (arr[j] >= arr[j + 1]))
			{
				cout << "the peak number is : " << arr[j] << endl;
			}
		}
		
	}
	else
		cout << "n/2 position is a peak" << endl;
	cout << "the peak number is : " << arr[n / 2] << endl;
	system("pause");
	return 0;
}