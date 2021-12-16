//program to detect cycle in a graph by using DFS traversal.
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
    void printAdjList();
    bool isCycle();
    bool checkCycle(int node, int parNode);
};
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
bool Graph::checkCycle(int currNode, int parNode)
{
    int m = adj[currNode].size();
    visited[currNode] = true;
    int cycle = false;
    for (int i = 0; i < m; i++)
    {
        int adjNode = adj[currNode][i];
        if (!visited[adjNode])
        {
            if (checkCycle(adjNode, currNode))
                return true;
        }
        else if (parNode != adjNode)
        {
            return true;
        }
    }
    return false;
}
bool Graph::isCycle()
{
    clearVisited();
    for (auto itr = adj.begin(); itr != adj.end(); itr++)
    {
        int node = itr->first;
        if (!visited[node]) {
            if (checkCycle(node, -1)) return true;
        }
    }
    return false;
}
int main()
{
    int n;
    cout << "Enter no. of edges : ";
    cin >> n;
    Graph g(n);
    g.printAdjList();
    if (g.isCycle())
        cout << "Graph contains cycle";
    else
        cout << "Graph does not contains cycle";
    return 0;
}