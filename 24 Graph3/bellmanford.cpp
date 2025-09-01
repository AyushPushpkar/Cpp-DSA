#include <bits/stdc++.h>
using namespace std;

//? tc : o(EV)
// v - vertices
// s - src

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    vector<int> dist(V, 1e8);
    dist[S] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if (dist[u] != 1e8 && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Nth relaxation to check negative cycle
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int w = it[2];
        if (dist[u] != 1e8 && dist[u] + w < dist[v])
        {
            return {-1}; // Negative cycle detected
        }
    }

    return dist;
}

int main()
{
    int V = 5; // number of vertices
    int E = 8; // number of edges

    vector<vector<int>> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    int source = 0;

    vector<int> dist = bellman_ford(V, edges, source);

    if (dist.size() == 1 && dist[0] == -1)
    {
        cout << "Graph contains a negative weight cycle\n";
    }
    else
    {
        cout << "Shortest distances from source " << source << ":\n";
        for (int i = 0; i < V; i++)
        {
            cout << "Vertex " << i << " : ";
            if (dist[i] == 1e8)
                cout << "INF";
            else
                cout << dist[i];
            cout << "\n";
        }
    }

    return 0;
}
