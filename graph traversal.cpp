#include<bits/stdc++.h>
using namespace std;
class Graph
{
private:
    int edgeCount;
    unordered_map<int, bool>visited;
    map<int, vector<int>>adj;
public:
    Graph(int edgeCount)
    {
        this->edgeCount = edgeCount;
        visited.clear();
        adj.clear();
        int a, b;
        cout << "enter " << edgeCount << " edges : \n";
        for (int i = 0; i < edgeCount; i++)
        {
            cin >> a >> b;
            addEdge(a, b);
        }
    }
    void clearVisited() { visited.clear(); }
    void addEdge(int a, int b);
    void bfs();
    void dfs();
    void _dfs(int node);
    void printAdjList();
};
void Graph::printAdjList()
{
    for (auto itr = adj.begin(); itr != adj.end(); itr++)
    {
        int i = itr->first;
        int m = adj[i].size();
        cout << i << " -> ";
        for (int j = 0; j < m; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
}
void Graph::addEdge(int a, int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}
void Graph::bfs()
{
    visited.clear();
    queue<int>q;
    int node, m;
    for (auto itr = adj.begin(); itr != adj.end(); itr++)
    {
        node = itr->first;
        if (!visited[node]) {
            q.push(node);
            visited[node] = true;
            while (!q.empty())
            {
                node = q.front();
                q.pop();
                m = adj[node].size();
                for (int i = 0; i < m; i++)
                {
                    int adjNode = adj[node][i];
                    if (!visited[adjNode]) {
                        q.push(adjNode);
                        visited[adjNode] = true;
                    }
                }
                cout << node << " ";
            }
            cout << "\n";
        }
    }
}
void Graph::_dfs(int node)
{
    int m = adj[node].size();
    cout << node << " ";
    visited[node] = true;
    for (int i = 0; i < m; i++) {
        int adjNode = adj[node][i];
        if (!visited[adjNode])
            _dfs(adjNode);
    }
}
void Graph::dfs()
{
    visited.clear();
    for (auto itr = adj.begin(); itr != adj.end(); itr++)
    {
        int node = itr->first;
        if (!visited[node]) {
            _dfs(node);
            cout << "\n";
        }
    }
}
int main()
{
    int n;
    cout << "Enter no. of edges : ";
    cin >> n;
    Graph g(n);
    cout << "adjacency list :\n";
    g.printAdjList();
    cout << "BFS traversal :\n";
    g.bfs();
    cout << "DFS traversal :\n";
    g.dfs();
}