// one dimensinal vesion finding peak number.

#include <iostream>
using namespace std;

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 5, 10, 16, 14, 15 };
	//length of array n
	int n = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int j = 1;
	while (j < n)
	{
		if ((arr[j] >= arr[i]) && (arr[j] >= arr[j + 1]))
		{
			cout << "the peak number is : " << arr[j] << endl;
		}
		++i;
		++j;
	}
	system("pause");
	return 0;
}