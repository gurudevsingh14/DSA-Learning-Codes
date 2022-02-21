#include<bits/stdc++.h>
using namespace std;
class Graph
{
private:
    int edgeCount;// no. of edges
    int V;//no. of vertex
    int *parent;
    int *rank;
    vector<vector<int>>result;//{source, destination, weight}
    vector<vector<int>>edges;//{source, destination, weight}
    int* subset;
public:
    Graph(int vertex, int edgeCount)
    {
        V = vertex;
        subset = new int[V];
        parent = new int[V];
        rank = new int[V];
        for (int i = 0; i < V; i++)
        {
            subset[i] = i;
            parent[i] = i;
            rank[i] = 0;
        }

        this->edgeCount = edgeCount;
        int a, b, weight;
        cout << "enter " << edgeCount << " edges : \n";
        for (int i = 0; i < edgeCount; i++)
        {
            cin >> weight >> a >> b;
            addEdge(a, b, weight);
        }
        sort(edges.begin(), edges.end(), compare);

    }
    static int compare(vector<int>a, vector<int>b)
    {
        if (a[2] < b[2])
            return true;
        return false;
    }
    void addEdge(int a, int b, int weight);
    void KruskalMst();
    void printMst();
    int find(int x);
    void unionV(int x, int y);
    void displayEdge();
};
void Graph::addEdge(int a, int b, int weight)
{
    edges.push_back({a, b, weight});
}
int Graph::find(int x)
{
    if (parent[x] == x) {
        return x;
    }
    int root = find(parent[x]);
    parent[x] = root;
    return root;
}
void Graph::unionV(int x, int y)
{
    x = find(x);
    y = find(y);
    if (rank[x] > rank[y]) {
        parent[y] = x;
    }
    else if (rank[x] < rank[y]) {
        parent[x] = y;
    }
    else
    {
        parent[x] = y;
        rank[y]++;
    }
}
void Graph::KruskalMst()
{
    int counte = 0 ;
    for (int i = 0; counte < V - 1; i++)
    {
        int x = edges[i][0];
        int y = edges[i][1];
        int xroot = find(x);
        int yroot = find(y);
        if (xroot != yroot)
        {
            result.push_back({x, y, edges[i][2]});
            unionV(x, y);
            counte++;
        }
    }
    printMst();
}
void Graph::printMst()
{
    int sum = 0;
    for (auto x : result)
    {
        sum += x[2];
        cout << x[0] << " -> " << x[1] << " = " << x[2] << "\n";
    }
    cout << "cost of minimum spanning tree = " << sum << "\n";
}
int main()
{
    int v, e;
    cout << "Enter no. of vertex : ";
    cin >> v;
    cout << "Enter no. of edges : ";
    cin >> e;
    Graph g(v, e);
    g.KruskalMst();
}