#include <bits/stdc++.h>
using namespace std;

// online queries
// return list : num of islands after each query

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

    bool isConnected(int u, int v)
    {
        return find(u) == find(v);
    }
};

vector<int> numIslands(int n, int m, vector<vector<int>> &operations)
{

    DisjointSet dsu(n * m);

    vector<int> noIsland;
    vector<vector<int>> islands(n, vector<int>(m, 0));

    int dx[] = {0, -1, 0, 1};
    int dy[] = {1, 0, -1, 0};

    int cnt = 0;

    for (auto it : operations)
    {

        int x = it[0];
        int y = it[1];

        if (islands[x][y] == 1)
        {
            noIsland.push_back(cnt);
            continue;
        }

        islands[x][y] = 1;

        cnt++;

        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (newx < n && newx >= 0 && newy < m && newy >= 0)
            {
                if (islands[newx][newy] == 1)
                {
                    int nodeNo = x * m + y;
                    int adjnodeNo = newx * m + newy;
                    if (!dsu.isConnected(nodeNo, adjnodeNo))
                    {
                        cnt--;
                        dsu.unite(nodeNo, adjnodeNo);
                    }
                }
            }
        }

        noIsland.push_back(cnt);
    }

    return noIsland;
}
