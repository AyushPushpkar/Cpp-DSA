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

vector<vector<string>> mergeDetails(vector<vector<string>> &details)
{

    int n = details.size();

    DisjointSet dsu(n);

    unordered_map<string, int> mapMail;

    // Step 1: Map each email to an account & union if repeated
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < details[i].size(); j++)
        {
            string mail = details[i][j];
            if (mapMail.find(mail) == mapMail.end())
                mapMail.insert({mail, i});
            else
            {
                dsu.unite(mapMail[mail], i);
            }
        }
    }
    // Step 2: Collect emails for each root
    vector<vector<string>> mergedMail(n);
    for (auto &it : mapMail)
    {
        string mail = it.first;
        int node = dsu.find(it.second);
        mergedMail[node].push_back(mail);
    }

    vector<vector<string>> ans;
    for (int i = 0; i < n; i++)
    {
        if (mergedMail[i].size() == 0)
            continue;
        sort(mergedMail[i].begin(), mergedMail[i].end());
        vector<string> temp;
        temp.push_back(details[i][0]);
        for (auto it : mergedMail[i])
        {
            temp.push_back(it);
        }
        ans.push_back(temp);
    }
    return ans;
}
