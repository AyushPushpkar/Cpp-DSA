#include <bits/stdc++.h>
using namespace std;

//? greedy
//* tc : o(ElogE)
// sum of mst weight

int primsAlgo(int n, vector<vector<int>> &edges)
{
    int src = 0;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> pq_min;

    pq_min.push({0, {src, -1}});
    vector<long long> vis(n, 0);

    vector<pair<int, int>> mst;
    int sum = 0;

    while (!pq_min.empty())
    {
        pair<long long, pair<int, int>> topEL = pq_min.top();
        pq_min.pop();

        long long dist = topEL.first;
        int node = topEL.second.first;
        int parent = topEL.second.second;

        if (vis[node] == 1)
            continue;
        if (parent != -1)
        {
            mst.push_back({parent, node});
            sum += dist;
        }
        vis[node] = 1;

        for (auto it : adj[node])
        {
            int adjnode = it.first;
            int wt = it.second;
            if (vis[adjnode] == 0)
                pq_min.push({wt, {adjnode, node}});
        }
    }
    return sum;
}

int main()
{
    int n = 5; // number of nodes (0 to 4)
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}};

    cout << "MST total weight = " << primsAlgo(n, edges) << "\n";
    return 0;
}
