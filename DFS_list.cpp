// #include <bits/stdc++.h>
// using namespace std;

// class Graph
// {
//     int V;
//     list<int> *adj;

//     void dfsUtil(int v, vector<bool> &already_seen);

//   public:
//     static int cnt;
//     Graph(int v)
//     {
//         this->V = v;
//         adj = new list<int>[v];
//     }
//     void add_edge(int a, int b)
//     {
//         adj[a].push_back(b);
//         adj[b].push_back(a);
//     }
//     void DFS();
//     void display();
// };

// void Graph::DFS(int v)
// {
//     int total = 0;
//     vector<bool> already_seen(V, false);
//     for(int i = 0; i < V; i++)
//     {
//         cnt++;
//         if(!already_seen[i])
//         {
//             total++;
//             dfsUtil(v, already_seen);
//         }
//     }

//     if(total == 1)
//         cout << endl << "Graph is connected" << endl;
//     else
//         cout << endl << "Graph is disconnected" << endl;
// }

// void Graph::dfsUtil(int v, vector<bool> &already_seen)
// {
//     cnt++;
//     already_seen[v] = true;
//     cout << v << " ";

//     list<int>::iterator i;
//     for(i = adj[v].begin(); i != adj[v].end(); i++)
//         if(!already_seen[*i])
//             dfsUtil(*i, already_seen);
// }

// void Graph::display()
// {
//     cout << endl << "Graph is " << endl;

//     for(int i = 0; i < V; i++)
//     {
//         cout << i << ": ";
//         list<int>::iterator j;
//         for(j = adj[i].begin(); j != adj[i].end(); j++)
//             cout << *j << " ";
//         cout << endl;
//     }
// }

// int Graph::cnt = 0;

// int main()
// {
//     int n;
//     cout << "Enter the number of vertices" << endl;
//     cin >> n;

//     Graph g(n);

//     int a, b;
//     cout << "Enter all edges" << endl;
//     cout << "Enter EOF to stop" << endl;

//     while(cin >> a >> b)
//         g.add_edge(a, b);

//     g.DFS(0);
//     cout << "cnt value is " << g.cnt << endl;
//     g.display();

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int>* adj;
    bool cycle;
    void dfsUtil(int v, bool vis[], int parent);
public:
    Graph(int n)
    {
        this->V = n;
        adj = new list<int>[n];
        cycle = false;
    }
    void add_edge(int a, int b)
    {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    void DFS();
};

void Graph::DFS()
{
    bool visited[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    cout << "DFS traversal is ";

    int total = 0;
    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            total++;
            dfsUtil(i, visited, -1);
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

void Graph::dfsUtil(int v, bool vis[], int parent)
{
    vis[v] = true;

    cout << v << " ";

    list<int>::iterator it;

    for(it = adj[v].begin(); it != adj[v].end(); it++)
    {
        if(!vis[*it])
            dfsUtil(*it, vis, v);
        else if(*it != parent)
            cycle = true;
    }
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
