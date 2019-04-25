#include <bits/stdc++.h>
using namespace std;

void print(vector< vector<int> > MF);
int knapsack(int wt[], int pr[], int n, int c);

int main()
{
	int total_items;
	cout << "Enter the total number of items" << endl;
	cin >> total_items;

	int capacity;
	cout << "Enter the capacity" << endl;
	cin >> capacity;

	int weights[total_items+1];
	weights[0] = 0;

	cout << "Enter the weights of " << total_items << " items" << endl;
	for(int i = 1; i <= total_items; i++)
		cin >> weights[i];

	int profits[total_items+1];
	profits[0] = 0;

	cout << "Enter the profits of " << total_items << " items" << endl;
	for(int i = 1; i <= total_items; i++)
		cin >> profits[i];

	cout << "Maximum weight is " << knapsack(weights, profits, total_items, capacity) << endl;

	return 0;
}


int knapsack(int wt[], int pr[], int n, int c)
{
	vector< vector<int> > MF(n+1, vector<int>(c+1, -1));
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= c; j++)
		{
			cnt++;
			if(i == 0 || j == 0)
				MF[i][j] = 0;
			else if(wt[i] <= j)
				MF[i][j] = max(MF[i-1][j], pr[i] + MF[i-1][j-wt[i]]);
			else
				MF[i][j] = MF[i-1][j];
		}
	}

	//print(MF);

	return MF[n][c];
}

void print(vector< vector<int> > MF)
{
	for(int i = 0; i < MF.size(); i++)
	{
		for(int j = 0; j < MF[i].size(); j++)
			cout << setw(3) << MF[i][j] << " ";
		cout << endl;
	}

	cout << endl;
}
