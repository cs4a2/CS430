#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void quickSort(int arr[], int low, int high);
int  partition(int arr[], int low, int high);
void printArray(int arr[], int numOfElements);

int main()
{
	/*
	int testcase;
	cout << "Enter the number of testcases" << endl;
	cin >>  testcase;

	int numOfElements = 0;

	ofstream worst("quick_worst.dat", ios::trunc);

	while(testcase--)
	{
		numOfElements += 10;

		int arr[numOfElements];

		srand(time(0));

		for(int index = 0; index < numOfElements; index++)
			arr[index] = rand() % numOfElements;

		cnt = 0;
		quickSort(arr, 0, numOfElements-1);

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

	quickSort(arr, 0, n-1);

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

void quickSort(int arr[], int low, int high)
{
	cnt++;
	if(low < high)
	{
		int pos;
		pos = partition(arr, low, high);
		quickSort(arr, low, pos-1);
		quickSort(arr, pos+1, high);

	}
}

int  partition(int arr[], int low, int high)
{
	int pivot = arr[low];
	int i, j;
	for(i = low + 1, j = high; ;)
	{
		cnt++;

		while(arr[i] <= pivot)
			i++;

		while(arr[j] > pivot)
			j--;

		if(j < i)
			break;

		swap(arr[i], arr[j]);
	}

	swap(arr[low], arr[j]);

	return j;
}
