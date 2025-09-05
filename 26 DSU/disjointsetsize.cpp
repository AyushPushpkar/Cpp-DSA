#include <bits/stdc++.h>
using namespace std;

/*
    Disjoint Set (Union-Find) - Union by Size + Path Compression
*/

class DisjointSetSize
{
private:
    vector<int> parent, size;

public:
    DisjointSetSize(int n)
    {
        parent.resize(n);
        size.resize(n, 1); // each set initially has size 1
        for (int i = 0; i < n; i++)
            parent[i] = i;
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

        if (pu == pv)
            return; // already same set

        // attach smaller tree to larger tree
        if (size[pu] < size[pv])
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

    bool connected(int u, int v)
    {
        return find(u) == find(v);
    }
};

// Example Usage
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    DisjointSetSize ds(7);

    ds.unite(5, 6);
    ds.unite(0, 1);
    ds.unite(1, 2);

    cout << "Are 5 and 6 connected? " << (ds.connected(5, 6) ? "Yes" : "No") << "\n";
    cout << "Are 0 and 2 connected? " << (ds.connected(0, 2) ? "Yes" : "No") << "\n";

    ds.unite(2, 5);

    cout << "After uniting 2 and 5, Are 0 and 6 connected? "
         << (ds.connected(0, 6) ? "Yes" : "No") << "\n";

    return 0;
}
