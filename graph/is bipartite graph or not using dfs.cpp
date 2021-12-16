//program to check bipartite graph by using DFS traversal.
#include<bits/stdc++.h>
using namespace std;
class Graph
{
private:
    int edgeCount;
    unordered_map<int, bool>visited;
    map<int, vector<int>>adj;//adjacency list
    int blue = 1;
    int green = 2;
    unordered_map<int, int>colored;
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
    void reset();
    void addEdge(int a, int b);
    void printAdjList();
    bool isBipartite();
    bool checkBipartite(int node);
};
void Graph::reset()
{
    visited.clear();
    colored.clear();
}
void Graph::addEdge(int a, int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}
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
bool Graph::checkBipartite(int currNode)
{
    if (!visited[currNode]) {
        visited[currNode] = true;
        colored[currNode] = blue;
    }
    int m = adj[currNode].size();
    for (int adjNode : adj[currNode])
    {
        if (!visited[adjNode]) {
            visited[adjNode] = true;
            if (colored[currNode] == blue)
                colored[adjNode] = green;
            else
                colored[adjNode] = blue;
            if (!checkBipartite(adjNode)) return false;
        }
        else if (colored[currNode] == colored[adjNode])
            return false;
    }
    return true;
}
bool Graph::isBipartite()
{
    reset();
    unordered_map<int, int>colored;
    for (auto itr = adj.begin(); itr != adj.end(); itr++)
    {
        int node = itr->first;
        if (!visited[node]) {
            if (!checkBipartite(node)) return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cout << "Enter no. of edges : ";
    cin >> n;
    Graph g(n);
    g.printAdjList();
    if (g.isBipartite())
        cout << "Graph is Bipartite graph";
    else
        cout << "Graph is not Bipartite graph";
    return 0;
}