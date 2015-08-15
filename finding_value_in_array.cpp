#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

int main()
{
	int arr[] = { 31, 41, 59, 26, 411, 58 };
	//finding the value in the array
	int value = 31;
	//length of array
	int length = sizeof(arr) / sizeof(0);
	for (int i = 0; i < length; ++i)
	{
		if (arr[i] == value)
		{
			cout << arr[i];
			return 0;
		}
		
	}
	cout << "cannot find the value" << endl;
	system("pause");
	return 0;
}