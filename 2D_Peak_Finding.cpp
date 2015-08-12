﻿#include <iostream>
#include <string>
#include <array>
using namespace std;

int main()
{
	int arr[3][5] = {
		{ 1, 2, 3, 4, 5 },
		{ 1, 2, 7, 4, 5 },
		{ 1, 2, 3, 4, 5 }
	};
	int temp = 0;
	// length of row
	int row = sizeof(arr) / sizeof(arr[0]);
	// length of column
	int j = sizeof(arr[0]) / sizeof(int);
	cout << "the length of row is : " << row << endl;
	cout << "the length of col is : " << j << endl;

	for (int i = 0; i < row; ++i)
	{
		// find global max on col/2
		for (int a = 0; a <= j / 2; ++a)
		{
			if (arr[i][a] >= temp)
			{
				temp = arr[i][a];
			}
		}
		//cout << "the maximum number for " << i + 1 << " row is : " << temp << endl;

		//recurse to the left 
		if (temp < arr[i][j / 2 - 1]){
			for (int a = 0; a <= j / 2; ++a)
			{
				if (arr[i][a] >= temp)
				{
					temp = arr[i][a];
				}
			}
			cout << temp << endl;
		}
		//recurse to the right array
		else if (temp > arr[i][j / 2 + 1]){
			cout << temp << endl;
		}
		else
			cout << arr[i / 2][j] << endl;

	}
	system("pause");
	return 0;
}