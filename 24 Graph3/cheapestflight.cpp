#include <bits/stdc++.h>
using namespace std;

//? Time complexity: O(E * log V)

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<vector<pair<int, int>>> adj(n);
    for (auto &flight : flights)
    {
        int from = flight[0];
        int to = flight[1];
        int cost = flight[2];
        adj[from].push_back({to, cost});
    }

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}}); // {stops, {node, cost}}

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    while (!q.empty())
    {
        int stops = q.front().first;
        int node = q.front().second.first;
        int cost_so_far = q.front().second.second;
        q.pop();

        if (stops > k)
            continue;

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int price = it.second;

            if (cost_so_far + price < dist[adjNode])
            {
                dist[adjNode] = cost_so_far + price;
                q.push({stops + 1, {adjNode, dist[adjNode]}});
            }
        }
    }

    return dist[dst] == INT_MAX ? -1 : dist[dst];
}

int main()
{
    int n = 5;
    vector<vector<int>> flights = {
        {0, 1, 1},
        {1, 2, 1},
        {0, 2, 5},
        {2, 3, 5},     
        {3, 4, 7}     
    };
    int src = 0;
    int dst = 3;
    int k = 2;

    int ans = findCheapestPrice(n, flights, src, dst, k);

    cout << ans << endl;

    return 0;
}
