#include<bits/stdc++.h>
using namespace std;
int graph[1000][1000];
int n;//number of nodes;
void input()
{
    int edges;//number of edges
    cout << "enter no. of nodes : ";
    cin >> n;
    cout << "enter no. of edges : ";
    cin >> edges;
    int a, b, weight;
    cout << "enter " << edges << " edges with their weight";
    for (int i = 0; i < edges; i++)
    {
        cin >> a >> b >> weight;
        graph[a][b] = weight;
        graph[b][a] = weight;
    }
}
int minKey(bool mst[], int dist[])
{
    int node = -1;
    int minDist = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (dist[i] < minDist && mst[i] == false)
        {
            minDist = dist[i];
            node = i;
        }
    }
    return node;
}
void print(int parent[])
{
    for (int i = 1; i < n; i++)
    {
        cout <<  parent[i] << " " << i << " " << graph[i][parent[i]] << "\n";
    }
    cout << "\n";
}
void primsAlgo()
{
    bool mst[n];
    int parent[n];
    int dist[n];
    memset(mst, false, sizeof(mst));
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }
    dist[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int node = minKey(mst, dist);
        mst[node] = true;
        for (int adj = 0; adj < n; adj++)
        {
            if (graph[node][adj] != 0 && mst[adj] == false && dist[adj] > graph[node][adj])
            {
                dist[adj] = graph[node][adj];
                parent[adj] = node;
            }
        }
    }
    print(parent);
}
int main()
{
    memset(graph, 0, sizeof(graph));
    input();
    primsAlgo();
    return 0;
}