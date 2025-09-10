#include <bits/stdc++.h>
using namespace std;

// mst

class DisjointSet
{
private:
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        size.resize(n + 1, 1);
    }

    int find(int u)
    {

        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v)
    {

        int pu = find(u);
        int pv = find(v);

        if (pv == pu)
            return;

        if (size[pv] > size[pu])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    bool isConnected(int u, int v)
    {
        return find(u) == find(v);
    }
};

int kruskalAlgo(int n, vector<vector<int>> *edges)
{

    // convert pointer to reference for ease
    auto &E = *edges;

    sort(E.begin(), E.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[2] < b[2]; }); // MlogM

    DisjointSet dsu(n);
    long long totalWeight = 0;
    int edgeCount = 0;

    // M x 4 x alpha X 2
    for (auto &e : E)
    {
        int u = e[0], v = e[1], w = e[2];
        if (dsu.find(u) != dsu.find(v))
        {
            dsu.unite(u, v);
            totalWeight += w;
            edgeCount++;
            // Stop if we already have n-1 edges
            if (edgeCount == n - 1)
                break;
        }
    }

    return (int)totalWeight;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 5; // number of nodes (0 to 4)
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}};

    int mstWeight = kruskalAlgo(n, &edges);
    cout << "Total weight of MST = " << mstWeight << "\n";

    return 0;
}
