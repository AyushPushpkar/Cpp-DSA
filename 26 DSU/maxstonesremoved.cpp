#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
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

    int getsize(int u)
    {
        int usize = size[u];
        return usize;
    }

    bool isConnected(int u, int v)
    {
        return find(u) == find(v);
    }
};

int maxRemoved(vector<vector<int>> &stones)
{

    int n = stones.size();

    int maxRow, maxCol = 0;
    for (auto it : stones)
    {
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[0]);
    }

    DisjointSet dsu(maxRow + maxCol + 1);

    unordered_map<int, int> stoneNodes;

    for (auto it : stones)
    {
        int row = it[0];
        int col = it[1] + maxRow + 1;
        dsu.unite(row, col);
        stoneNodes[row] = 1;
        stoneNodes[col] = 1;
    }

    int cnt = 0;
    for (auto it : stoneNodes)
    {
        if (dsu.find(it.first) == it.first)
            cnt++;
    }

    return n - cnt;
}
