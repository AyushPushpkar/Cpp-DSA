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

bool dlstraversal_goal(vector<int> adj[], int node, int goal,
                       int vis[], vector<int> &path, int limit)
{
    if (limit < 0)
        return false;

    vis[node] = 1;
    path.push_back(node);

    if (node == goal)
        return true;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dlstraversal_goal(adj, it, goal, vis, path, limit - 1))
                return true;
        }
    }

    path.pop_back(); // backtrack
    return false;
}

vector<int> dlsgraph_goal(int n, vector<int> adj[], int startnode,
                          int goal, int limit)
{
    vector<int> path;
    int vis[n + 1] = {0};

    bool found = dlstraversal_goal(adj, startnode, goal, vis, path, limit);

    if (found)
        return path;
    else
        return {};
}

int main()
{
    int n = 8;

    vector<int> adj[n + 1];

    vector<pair<int, int>> edges = {
        {1, 2}, {1, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}, {7, 8}};

    for (auto edge : edges)
    {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start = 1;
    int goal = 8;
    int depth_limit = 6;

    vector<int> ans = dlsgraph_goal(n, adj, start, goal, depth_limit);

    if (!ans.empty())
    {
        cout << "Goal Found! Path: ";
        for (int it : ans)
            cout << it << " ";
        cout << endl;
    }
    else
    {
        cout << "Goal NOT found within depth limit " << depth_limit << endl;
    }

    return 0;
}
