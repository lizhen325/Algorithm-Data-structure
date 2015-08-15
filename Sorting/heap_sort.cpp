// heap sort

#include <iostream>

using namespace std;

void max_heapify(int a[], int i, int n)
{
	int l, r, lar;
	l = 2 * i;
	r = (2 * i) + 1;
	if (l <= n && a[l] > a[i])
		lar = l;
	else
		lar = i;
	if (r <= n && a[r] > a[lar])
		lar = r;
	if (lar != i)
	{
		swap(a[i], a[lar]);
		max_heapify(a, lar, n);
	}
}
void build_max_heap(int a[], int n)
{
	for (int i = n / 2; i >= 1; i--)
		max_heapify(a, i, n);
}

void heapsort(int a[], int n)
{
	build_max_heap(a, n);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[1], a[i]);
		max_heapify(a, 1, i - 1);
	}
}
int main()
{
	int arr[] = { 3, 1, 5, 7, 4, 8, 10, 14, 13 };
	int n = sizeof(arr) / sizeof(0);
	cout << n << endl;
	heapsort(arr, n);
	for (int i = 0; i < n; ++i)
		cout << arr[i] << ",";
	system("pause");
	return 0;
}