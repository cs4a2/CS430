#include <bits/stdc++.h>
using namespace std;

void read(vector< vector<int> > &M, int n);
void print(vector< vector<int> > M, int n);
void floyd(vector< vector<int> > &M, int n);

int main()
{
    int n;
    cout << "Enter the number of vertices" << endl;
    cin >> n;

    vector< vector<int> > M(n, vector<int>(n, 9999));

    for(int i = 0; i < n; i++)
        M[i][i] = 0;

    read(M, n);

    cout << "Readed graph" << endl;
    print(M, n);

    floyd(M, n);

    cout << "After applying floyd's algorithm" << endl;
    print(M, n);

    return 0;
}

void read(vector< vector<int> > &M, int n)
{
    cout << "Enter edges" << endl;
    cout << "Enter EOF to exit" << endl;

    int a, b;
    while(cin >> a >> b)
    {
        int w;
        cin >> w;

        M[a][b] = w;
    }
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

void floyd(vector< vector<int> > &M, int n)
{
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                M[i][j] = min(M[i][j], M[i][k]+M[k][j]);
}

