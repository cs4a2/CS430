#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void copy(int dest[], int j, int m, int source[], int i, int n);
void mergeSort(int arr[], int numOfElements);
void printArray(int arr[], int numOfElements);

int main()
{
	/*
	int testcase;
	cout << "Enter the number of testcases" << endl;
	cin >>  testcase;

	int numOfElements = 0;

	ofstream worst("F:\\algorithms\\worst.dat", ios::trunc);

	while(testcase--)
	{
		numOfElements += 10;

		int arr[numOfElements];

		srand(time(0));

		for(int index = 0; index < numOfElements; index++)
			arr[index] = rand() % numOfElements;

		cnt = 0;
		mergeSort(arr, numOfElements);

		worst << numOfElements  << " " << cnt << endl;
	}
	*/

	int n;
	cout << "Enter the number of elements" << endl;
	cin >> n;

	int arr[n];
	cout << "Enter array elements" << endl;
	for(int i = 0; i < n; i++)
	    cin >> arr[i];

	mergeSort(arr, n);

	printArray(arr, n);

	return 0;
}

void printArray(int arr[], int numOfElements)
{
	cout << "Array elements are" ;
	int i;
	for(i = 0; i < numOfElements; i++)
		cout << " " << arr[i] ;
	cout << endl;
}

void copy(int dest[], int j, int m, int source[], int i, int n)
{
	while(i < n)
		dest[j++] = source[i++];
}

void merge(int b[], int b_size, int c[], int c_size, int arr[], int numOfElements)
{
	int i, j, k = 0;
	for(i = 0, j = 0; i < b_size && j < c_size; k++, cnt++)
	{
		if(b[i] <= c[j])
			arr[k] = b[i++];
		else
			arr[k] = c[j++];
	}

	if(i == b_size)
		copy(arr, k, numOfElements, c, j, c_size);
	else
		copy(arr, k, numOfElements, b, i, b_size);
}

void mergeSort(int arr[], int numOfElements)
{
	if(numOfElements > 1)
	{
		cnt++;

		int b_size = floor(numOfElements / 2);
		int b[b_size];
		copy(b, 0, b_size, arr, 0, b_size);

		int c_size = numOfElements - b_size;
		int c[c_size];
		copy(c, 0, c_size, arr, b_size, numOfElements);

		mergeSort(b, b_size);
		mergeSort(c, c_size);

		merge(b, b_size, c, c_size, arr, numOfElements);
	}
}
