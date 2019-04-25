#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    bool cycle;
    list<int> *adj;
public:
    Graph(int n)
    {
        cycle = false;
        this->V = n;
        adj = new list<int>[n];
    }
    void add_edge(int a, int b)
    {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    void BFS();
};

void Graph::BFS()
{
    vector<int> parent(V, -1);
    vector<bool> visited(V, false);

    queue<int> que;
    int total = 0;

    cout << "BFS traversal is ";

    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            total++;
            que.push(i);
            visited[i] = true;

            while(!que.empty())
            {
                int u = que.front();
                que.pop();

                cout << u  << " ";

                list<int>::iterator it;
                for(it = adj[u].begin(); it != adj[u].end(); it++)
                {
                    if(!visited[*it])
                    {
                        que.push(*it);
                        parent[*it] = u;
                        visited[*it] = true;
                    }
                    else if(parent[u] != *it)
                        cycle = true;
                }
            }
        }
    }

    if(total == 1)
        cout << endl << "Graph is connected" << endl;
    else
        cout << endl << "Graph is disconnected" << endl;

    if(cycle)
        cout << "Cycle is present" << endl;
    else
        cout << "Cycle is not present" << endl;
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

    g.BFS();
    return 0;
}
