#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void sortArray(int arr[], int n);
void printArray(int arr[], int n);
int  binary_search(int arr[], int n, int key);

int main()
{
	/*
	int testcase;
	cout << "Enter the number of testcases" << endl;
	cin >>  testcase;

	int n = 0;

	ofstream avg("average.dat", ios::trunc);
	ofstream worst("worst.dat", ios::trunc);
	ofstream best("best.dat", ios::trunc);
	while(testcase--)
	{
		n += 10;

		int arr[n];

		srand(time(0));

		for(int index = 0; index < n; index++)
			arr[index] = rand() % n;

		sort(arr, arr+n);

		int key = rand() % (n/2);
		cnt = 0;
		binary_search(arr, n, key);
		avg << n  << " " << cnt << endl;

		cnt = 0;
		binary_search(arr, n, arr[(n-1)/2]);
		best << n  << " " << cnt << endl;

		cnt = 0;
		binary_search(arr, n, n);
		worst << n  << " " << cnt << endl;
	}
	*/

	int n;
	cout << "Enter the number of elements" << endl;
	cin >> n;

	int arr[n];
	cout << "Enter array elements" << endl;
	for(int i = 0; i < n; i++)
	    cin >> arr[i];

	int key;
	cout << "Enter a key to be searched" << endl;
	cin >> key;

	int result = binary_search(arr, n, key);

	if(result == -1)
		cout << "Key is not present" << endl;
	else
		cout << "Key is present at location " << result << endl;

	return 0;
}

void printArray(int arr[], int n)
{
	cout << "Array elements are" << endl;
	int i;
	for(i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int  binary_search(int arr[], int n, int key)
{
	int low  = 0;
	int high = n - 1;
	int mid;

	while(low <= high)
	{
		cnt++;

		mid = (low + high) / 2;

		if(arr[mid] == key)
			return mid;
		else if(arr[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return -1;
}
