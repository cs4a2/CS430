#include <bits/stdc++.h>
using namespace std;

void read(vector< vector<int> > &M, int n);
void print(vector< vector<int> > M, int n);
void warshall(vector< vector<int> > &M, int n);

int main()
{
	int n;
	cout << "Enter the number of vertices" << endl;
	cin >> n;

	vector< vector<int> > M(n, vector<int>(n, 0));

	read(M, n);

	cout << "Readed graph" << endl;
	print(M, n);

	warshall(M, n);

	cout << "After applying warshall's algorithm" << endl;
	print(M, n);

	return 0;
}

void read(vector< vector<int> > &M, int n)
{
	cout << "Enter edges" << endl;
	cout << "Enter EOF to exit" << endl;

	int a, b;
	while(cin >> a >> b)
		M[a][b] = 1;
}

void print(vector< vector<int> > M, int n)
{
	cout << "Graph is " << endl;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << M[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

void warshall(vector< vector<int> > &M, int n)
{
	for(int k = 0; k < n; k++)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
				M[i][j] = M[i][j] | (M[i][k] & M[k][j]);
		}
	}
}

