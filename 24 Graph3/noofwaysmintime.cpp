#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>> &roads)
{
    int src = 0, dst = n - 1;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < roads.size(); i++)
    {
        int u = roads[i][0];
        int v = roads[i][1];
        int w = roads[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq_min;

    pq_min.push({0, src});
    vector<long long> dis(n, LLONG_MAX);
    dis[src] = 0;

    int mod = (int)(1e9 + 7);

    vector<int> ways(n, 0);
    ways[src] = 1;

    while (!pq_min.empty())
    {
        pair<long long, int> node = pq_min.top();
        long long dist = node.first;
        int y = node.second;

        pq_min.pop();

        if (dist > dis[y])
            continue;

        for (auto it : adj[y])
        {
            int adjnode = it.first;
            int wt = it.second;
            long long newDist = dist + wt;

            if (newDist < dis[adjnode])
            {
                dis[adjnode] = newDist;
                ways[adjnode] = ways[y];
                pq_min.push({newDist, adjnode});
            }
            else if (newDist == dis[adjnode])
            {
                ways[adjnode] = (ways[adjnode] + ways[y]) % mod;
            }
        }
    }
    return ways[dst] % mod;
}