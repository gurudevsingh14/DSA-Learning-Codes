//program to check bipartite graph by using BFS traversal.
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
    bool isBipartite();
    bool checkBipartite(int node);
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
bool Graph::checkBipartite(int currNode)
{
    unordered_map<int, int>color;
    int blue = 1;
    int green = 2;
    queue<int>q;
    q.push(currNode);
    visited[currNode] = true;
    color[currNode] = blue;
    while (!q.empty())
    {
        currNode = q.front();
        q.pop();
        int m = adj[currNode].size();
        for (int i = 0; i < m; i++)
        {
            int adjNode = adj[currNode][i];
            if (!visited[adjNode])
            {
                visited[adjNode] = true;
                if (color[currNode] == blue)
                    color[adjNode] = green;
                else
                    color[adjNode] = blue;
                q.push(adjNode);
            }
            else if (color[adjNode] == color[currNode])
            {
                return false;
            }
        }
    }
    return true;
}
bool Graph::isBipartite()
{
    clearVisited();
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