#include <bits/stdc++.h>
using namespace std;

/*
 *       1
 *      / \
 *     2   3
 *      \ / \
 *       4   5
 *          / \
 *         6---7
 *              \
 *               8
 */

int timer = 1;

void dfstraversal(vector<vector<int>> &adj, int node, int parent, vector<int> &vis,
                  int tn[], int low[], vector<vector<int>> &bridges)
{

    vis[node] = 1;

    tn[node] = low[node] = timer;
    timer++;

    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (!vis[it])
        {
            dfstraversal(adj, it, node, vis, tn, low, bridges);
            low[node] = min(low[node], low[it]);
            if (low[it] > tn[node])
            {
                bridges.push_back({it, node});
            }
        }
        else
        {
            low[node] = min(low[node], low[it]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{

    vector<vector<int>> adj(n + 1);

    for (auto it : connections)
    {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n + 1, 0);

    int tn[n];
    int low[n];
    vector<vector<int>> bridges;

    dfstraversal(adj, 1, -1, vis, tn, low, bridges); 

    return bridges;
}

int main()
{
    int n = 8;  // number of vertices
    int m = 10; // number of edges

    // predefined input edges
    vector<vector<int>> edges = {
        {1, 2},
        {1, 3},
        {2, 4},
        {3, 4},
        {3, 5},
        {5, 6},
        {5, 7},
        {6, 7},
        {7, 8}};

    vector<vector<int>> ans = criticalConnections(n, edges);

    for (auto it : ans)
    {
        cout << it[0] << "," << it[1] << endl;
    }
    cout << endl;

    return 0;
}