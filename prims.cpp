#include <bits/stdc++.h>
using namespace std;

int minVertex(int wt[], bool vis[], int n);
void prims(vector<vector<int> > M, int n);

int main()
{
    int n, e;
    cout << "Enter number of vertices and edges" << endl;
    cin >> n >> e;

    vector<vector<int> > M(n, vector<int>(n, 0));

    cout << "Enter edges and weights" << endl;
    for(int i = 0; i < e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        M[a][b] = M[b][a] = w;
    }

    prims(M, n);
    return 0;
}

void prims(vector<vector<int> > M, int n)
{
    int parent[n];
    bool visited[n];
    int weights[n];

    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
        weights[i] = INT_MAX;
    }

    weights[0] = 0;
    parent[0] = -1;

    for(int i = 0; i < n-1; i++)
    {
        int u = minVertex(weights, visited, n);
        visited[u] = true;

        for(int v = 0; v < n; v++)
        {
            if(M[u][v] && !visited[v] && M[u][v] < weights[v])
            {
                weights[v] = M[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Minimum Spanning tree contains" << endl;
    cout << "Edge\tWeight" << endl;
    for(int i = 1; i < n; i++)
    {
        if(i < parent[i])
            cout << i << "->" << parent[i] << "\t" << weights[i] << endl;
        else
            cout << parent[i] << "->" << i << "\t" << weights[i] << endl;

    }

    cout << endl;
}

int minVertex(int wt[], bool vis[], int n)
{
    int min = INT_MAX, index = -1;
    for(int i = 0; i < n; i++)
    {
        if(!vis[i] && wt[i] < min)
            min = wt[i], index = i;
    }

    return index;
}

