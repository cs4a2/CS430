#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void createHeap(int arr[], int n);
void Heapify(int arr[], int i, int n);
void printHeap(int arr[], int n);
void heapSort(int arr[], int n);

int main()
{
    // int size;
    // cin >> size;

    // int arr[size];
    // for(int i = 0; i <size; i++)
    //     cin >> arr[i];

    // heapSort(arr, size);

    // printHeap(arr, size);

    int tc = 50;
    int n = 0;

    ofstream worst("f:\\algorithms\\worst.dat", ios::trunc);

    while(tc--)
    {
        n += 10;

        int arr[n];
        for(int i = 0; i < n; i++)
            arr[i] = rand() % n;

        cnt = 0;
        heapSort(arr, n);

        worst << n << " " << cnt << endl;
    }

    return 0;
}

void createHeap(int arr[], int n)
{
    for(int i = n/2 - 1; i >= 0; i--)
        Heapify(arr, i, n);
}

void Heapify(int arr[], int i, int n)
{
    cnt++;
    int l = 2*i + 1;  // left child
    int r = 2*i + 2;  // right child

    int big = i;

    if(l < n && arr[l] > arr[big])
        big = l;

    if(r < n && arr[r] > arr[big])
        big = r;

    if(big != i)
    {
        swap(arr[i], arr[big]);
        Heapify(arr, big, n);
    }
}

void printHeap(int arr[], int n)
{
    cout << "Array is ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void heapSort(int arr[], int n)
{
    createHeap(arr, n);

    for(int i = n-1; i >= 0; i--)
    {
        cnt++;
        swap(arr[0], arr[i]);

        Heapify(arr, 0, i);
    }
}
