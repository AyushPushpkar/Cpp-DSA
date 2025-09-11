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

int numProvinces(int n, vector<vector<int>> adj)
{

    DisjointSet dsu(n);
    int num = 0;

    // M x 4 x alpha X 2
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == 1)
            {
                dsu.unite(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (dsu.find(i) == i)
        {
            num++;
        }
    }

    return num;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 5; // number of nodes (0 to 4)

    vector<vector<int>> adj = {
        {1, 1, 0, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 0, 1, 1}
    };

    int P = numProvinces(n, adj);
    cout << "No of Provinces = " << P << "\n";

    return 0;
}

