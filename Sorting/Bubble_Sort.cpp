//Bubble sort
//
#include <iostream>

using namespace std;


int main(){
	int arr[] = { 7, 2, 9, 4, 5, 6, 0, 8 };
	int n = sizeof(arr) / sizeof(int);
	int temp;
	bool swapping = true;
	while (swapping) {
		swapping = false;
		//don’t look at the last one
		for (int i = 0; i < n - 1; i++) 
		{
			//comparison
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swapping = true;
			}
		}
	}

	for (int i = 0; i < n; ++i)
		cout << arr[i];

	system("puase");
	return 0;
}
