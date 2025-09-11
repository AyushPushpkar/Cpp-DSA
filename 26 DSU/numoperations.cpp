#include <bits/stdc++.h>
using namespace std;

//? min num of operations to connect components
//! new edges can't be formed , edges can only be moved
//* we only need n-1 edges to connect n components

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
            parent[u] = find(parent[u]); // path compression
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

int numOperations(int n, vector<vector<int>> &connections)
{

    DisjointSet dsu(n);
    int num = 0;

    int extraEdges = 0;

    // M x 4 x alpha X 2
    for (auto it : connections)
    {
        if (dsu.isConnected(it[0], it[1]))
            extraEdges++;
        else
            dsu.unite(it[0], it[1]);
    }

    for (int i = 0; i < n; i++)
    {
        if (dsu.find(i) == i)
        {
            num++;
        }
    }

    int ans = num - 1;

    if (extraEdges >= ans)
        return ans;
    else
        return -1;
}
