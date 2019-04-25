#include <bits/stdc++.h>
using namespace std;

stack<int> stk;

class Graph
{
    int V;
    list<int> *adj;
    void dfsUtil(int v, bool vis[]);
public:
    Graph(int n)
    {
        this->V = n;
        adj = new list<int>[n];
    }
    void add_edge(int a, int b)
    {
        adj[a].push_back(b);
    }
    void DFS();
};

void Graph::DFS()
{
    bool visited[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
            dfsUtil(i, visited);
    }

    cout << "Topological order is ";
    while(!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

void Graph::dfsUtil(int v, bool vis[])
{
    vis[v] = true;

    list<int>::iterator it;
    for(it = adj[v].begin(); it != adj[v].end(); it++)
    {
        if(!vis[*it])
            dfsUtil(*it, vis);
    }

    stk.push(v);
}

int main()
{
    int n, e;
    cout << "Enter number of vertices and edges" << endl;
    cin >> n >> e;

    Graph g(n);

    cout << "Enter edges" << endl;
    for(int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        g.add_edge(a, b);
    }

    g.DFS();

    return 0;
}

