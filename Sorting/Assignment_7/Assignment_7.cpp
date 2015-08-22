#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>

using namespace std;

vector<int> vector_random;
vector<int> vector_reversed;
vector<int> vector_sorted;

/*  Implement a Heap class here (from the slides)  */

int heapSize = 5;
void PRINT(int a[]) {
	for (int i = 0; i < 5; i++) {
		cout << a[i] << ",";
	}
	cout << endl;
}

int parent(int i) {
	if (i == 1)
		return 0;

	if (i % 2 == 0)
		return ((i / 2) - 1);
	else
		return ((i / 2));
}

int left(int i) {
	return (2 * i) + 1;
}

int right(int i) {
	return (2 * i) + 2;
}

void heapify(int a[], int i) {
	int l = left(i), great;
	int r = right(i);
	if ((a[l] > a[i]) && (l < heapSize)) {
		great = l;
	}
	else {
		great = i;
	}
	if ((a[r] > a[great]) && (r < heapSize)) {
		great = r;
	}
	if (great != i) {
		int temp = a[i];
		a[i] = a[great];
		a[great] = temp;
		heapify(a, great);
	}
}

void BuildMaxHeap(int a[]) {
	for (int i = (heapSize - 1) / 2; i >= 0; i--) {
		heapify(a, i);
	}
}

void HeapSort(int a[]) {
	BuildMaxHeap(a);
	for (int i = heapSize; i > 0; i--) {
		int temp = a[0];
		a[0] = a[heapSize - 1];
		a[heapSize - 1] = temp;
		heapSize = heapSize - 1;
		heapify(a, 0);
	}

}


/* this is a possible prototype for the heapsort function */
/* the char* filename is just for printing the name, the file is opened and dealt with in the main() */
void heapsort(vector<int> &sortingvector, int number_of_elements, char* filename){
	
	int arr[100];
	// copy vector to array
	copy(sortingvector.begin(), sortingvector.end(), arr);

	/* After building the heap from the file, PRINT the current state of the heap before sorting */

	cout << "heap before sorting : " << filename << endl;
	BuildMaxHeap(arr);
	PRINT(arr);
	cout << "after heap sorting :" << filename << endl;
	HeapSort(arr);
	PRINT(arr);
}




int main(int argc, char** argv){//get filename from arguments
	char expression[100];
	int number;
	string line;
	ifstream input_file_random;
	ifstream input_file_reversed;
	ifstream input_file_sorted;
	argv[1] = "C:/Users/zhenli/Desktop/159201/Assignments/7/random_N_5.txt";
	argv[2] = "C:/Users/zhenli/Desktop/159201/Assignments/7/reversed_N_5.txt";
	argv[3] = "C:/Users/zhenli/Desktop/159201/Assignments/7/sorted_N_5.txt";
	input_file_random.open(argv[1]);
	input_file_reversed.open(argv[2]);
	input_file_sorted.open(argv[3]);

	//else {printf("The program needs 3 filenames, in this order: random, reversed and sorted.\n");exit(0);}
	int number_of_elements_random = 0;
	while (input_file_random >> number){
		getline(input_file_random, line);
		stringstream sline(line);
		vector_random.push_back(number);
		number_of_elements_random++;
	}
	/*Comment out this printout, this is just to check that the array was copied */
	cout << "random : ";
	for (int count = 0; count<number_of_elements_random; count++){
		printf("%d ", vector_random[count]);
	}
	printf("\n");
	/*end printout*/

	int number_of_elements_reversed = 0;
	while (input_file_reversed >> number){
		getline(input_file_random, line);
		stringstream sline(line);
		/*Comment out this printout, this is just to check that the file can be read */
		//		printf("%d ",number );	
		vector_reversed.push_back(number);
		number_of_elements_reversed++;
	}
	/*Comment out this printout, this is just to check that the array was copied */
	cout << "reversed : ";
	for (int count = 0; count<number_of_elements_reversed; count++){
		printf("%d ", vector_reversed[count]);
	}
	printf("\n");
	/*end printout*/


	int number_of_elements_sorted = 0;
	while (input_file_sorted >> number){
		getline(input_file_random, line);
		stringstream sline(line);
		/*Comment out this printout, this is just to check that the file can be read */
		//		printf("%d ",number );	
		vector_sorted.push_back(number);
		number_of_elements_sorted++;
	}
	/*Comment out this printout, this is just to check that the array was copied */
	cout << "sorted : ";
	for (int count = 0; count<number_of_elements_sorted; count++){
		printf("%d ", vector_sorted[count]);
	}
	printf("\n");
	/*end printout*/


	/* Implement or call your Heap sort here, the Heap class with methods should be copied/implemented before main() */
	heapsort(vector_random, number_of_elements_random, "random_N_5.txt");
	cout << endl;
	heapsort(vector_reversed, number_of_elements_reversed, "reversed_N_5.txt");
	cout << endl;
	heapsort(vector_sorted, number_of_elements_sorted, "sorted_N_5.txt");
	system("pause");
	return 0;
}
