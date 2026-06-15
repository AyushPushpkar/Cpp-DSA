#include <bits/stdc++.h>
using namespace std;
/*
Problem:
Find largest island area using DSU.
*/

// TC: O(rows × cols × α(n)) | SC: O(rows × cols)
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

int largestIslands(vector<vector<int>> &grid)
{

    int n = grid.size();
    int m = grid[0].size();

    DisjointSet dsu(n * m);

    int dx[] = {0, -1, 0, 1};
    int dy[] = {1, 0, -1, 0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            for (int k = 0; k < 4; i++)
            {
                int newx = i + dx[k];
                int newy = j + dy[k];
                if (newx < n && newx >= 0 && newy < m && newy >= 0)
                {
                    if (grid[newx][newy] == 1)
                    {
                        int nodeNo = i * m + j;
                        int adjnodeNo = newx * m + newy;
                        dsu.unite(nodeNo, adjnodeNo);
                    }
                }
            }
        }
    }

    int mx = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
                continue;
            set<int> components;

            for (int k = 0; k < 4; i++)
            {
                int newx = i + dx[k];
                int newy = j + dy[k];
                if (newx < n && newx >= 0 && newy < m && newy >= 0)
                {
                    if (grid[newx][newy] == 1)
                    {
                        int adjnodeNo = newx * m + newy;
                        components.insert(dsu.find(adjnodeNo));
                    }
                }
            }

            int sizeTotal = 0;
            for (auto it : components)
            {
                sizeTotal += dsu.getsize(it);
            }
            mx = max(mx, sizeTotal + 1);
        }
    }

    for (int i = 0; i < n * m; i++)
    {
        mx = max(mx, dsu.getsize(dsu.find(i)));
    }
    return mx;
}
