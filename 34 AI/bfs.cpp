#include <bits/stdc++.h>
using namespace std;

/*
*       1
*      / \
*     2   3
*      \ / \
*       4   5
*        \ / \
*         6---7
*              \
*               8
*/

vector<int> bfsgraph_goal(int n, vector<int> adj[], int startnode, int goal)
{
    vector<int> vis(n + 1, 0);
    vector<int> parent(n + 1, -1);   // ✅ to reconstruct path
    queue<int> q;

    vis[startnode] = 1;
    q.push(startnode);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        if (node == goal)   // ✅ GOAL TEST
            break;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                parent[it] = node;   // ✅ store parent
                q.push(it);
            }
        }
    }

    // ✅ reconstruct path
    vector<int> path;
    if (!vis[goal])
        return {};   // goal not found

    for (int v = goal; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    int n = 8;
    int m = 10;

    vector<int> adj[n + 1];

    vector<pair<int, int>> edges = {
        {1, 2}, {1, 3}, {2, 4}, {3, 4}, {3, 5},
        {4, 6}, {5, 6}, {5, 7}, {6, 7}, {7, 8}
    };

    for (auto edge : edges)
    {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start = 4;
    int goal = 8;

    vector<int> ans = bfsgraph_goal(n, adj, start, goal);

    if (!ans.empty())
    {
        cout << "Goal Found! Path: ";
        for (int it : ans)
            cout << it << " ";
        cout << endl;
    }
    else
    {
        cout << "Goal NOT found" << endl;
    }

    return 0;
}
