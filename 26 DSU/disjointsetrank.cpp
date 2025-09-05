// disjoint_set.cpp
#include <bits/stdc++.h>
using namespace std;

/*
    Disjoint Set (Union-Find) Data Structure
    ----------------------------------------
    Used to keep track of a set of elements partitioned into disjoint subsets.
    Main operations:
      1. find(u)      -> returns the representative (parent) of the set containing u
      2. union(u, v)  -> merges the sets containing u and v
    Optimizations:
      - Path Compression (for find)
      - Union by Rank / Size
*/

class DisjointSetRank
{
private:
    vector<int> parent, rank;

public:
    DisjointSetRank(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
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

        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
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

    DisjointSetRank ds(7);

    ds.unite(0, 1);
    ds.unite(1, 2);
    ds.unite(3, 4);

    cout << "Are 0 and 2 connected? " << (ds.connected(0, 2) ? "Yes" : "No") << "\n";
    cout << "Are 0 and 4 connected? " << (ds.connected(0, 4) ? "Yes" : "No") << "\n";

    ds.unite(2, 4);

    cout << "After uniting 2 and 4, Are 0 and 4 connected? "
         << (ds.connected(0, 4) ? "Yes" : "No") << "\n";

    return 0;
}