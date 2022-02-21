#include<bits/stdc++.h>
using namespace std;
class Graph
{
private:
    int eCount;
    int vCount;

    int *parent;
    int *rank;

    map<int, vector<int>>sets;
public:
    vector<vector<int>>edges;

    Graph(int vCount, int eCount)
    {
        this->vCount = vCount;
        this->eCount = eCount;

        parent = new int[vCount + 1];
        rank = new int[vCount + 1];

        for (int i = 0; i <= vCount; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }

        int a, b;
        cout << "enter " << eCount << " edges : \n";
        for (int i = 0; i < eCount; i++)
        {
            cin >> a >> b;
            addEdge(a, b);
        }
    }
    void addEdge(int a, int b);
    int find(int x);
    void unionEdges(int x, int y);
    void printSets();
};
void Graph::addEdge(int a, int b)
{
    edges.push_back({a, b});
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
void Graph::unionEdges(int x, int y)
{
    x = find(x);
    y = find(y);
    if (rank[x] > rank[y]) {
        parent[y] = x;
        sets[x].push_back(y);
    }
    else if (rank[x] < rank[y]) {
        parent[x] = y;
        sets[y].push_back(x);
    }
    else
    {
        parent[x] = y;
        sets[y].push_back(x);
        rank[y]++;
    }
}
void Graph::printSets()
{
    for (auto itr = sets.begin(); itr != sets.end(); itr++)
    {
        int i = itr->first;
        int m = sets[i].size();
        cout << "{ ";
        cout << i << " ";//printing root vertex
        unordered_map<int, bool>prevVertex;
        // printing connected child vertices
        for (int j = 0; j < m; j++)
        {
            if (prevVertex[sets[i][j]] == false)
                cout << sets[i][j] << " ";
            prevVertex[i] = true;
        }
        cout << "}\n";
    }
}
int main()
{
    int v, e;
    cout << "Enter no. of vertex : "; cin >> v;
    cout << "Enter no. of edge : "; cin >> e;
    Graph g(v, e);
    for (int i = 0; i < e; i++)
    {
        g.unionEdges(g.edges[i][0], g.edges[i][1]);
    }
    cout << "sets formed :\n";
    g.printSets();

    return 0;
}