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

// Depth-Limited Search (DLS) that stops when GOAL is found
bool dlstraversal_goal(vector<int> adj[],int node,int goal,vector<int> &vis,
        vector<int> &path,int limit)
        {
    if (limit < 0) return false;       // depth cutoff

    vis[node] = 1;
    path.push_back(node);

    if (node == goal)                  // ✅ goal test
        return true;

    for (auto nxt : adj[node])
    {
        if (!vis[nxt])
        {
            if (dlstraversal_goal(adj, nxt, goal, vis, path, limit - 1))
                return true;           // ✅ propagate success upwards
        }
    }

    path.pop_back();                   // backtrack
    return false;
}

// IDDFS that searches for a GOAL and returns the PATH
vector<int> iddfs_goal(int n, vector<int> adj[],int startnode,
                int goal, int max_depth){
                    
    for (int depth = 0; depth <= max_depth; depth++)
    {
        vector<int> vis(n + 1, 0);
        vector<int> path;

        bool found = dlstraversal_goal(adj, startnode, goal, vis, path, depth);

        if (found)
        {
            cout << "Goal " << goal << " found at depth " << depth << "\n";
            return path;              // ✅ return path as soon as goal is found
        }
    }

    // not found within max_depth
    return {};
}

int main()
{
    int n = 8;

    vector<int> adj[n + 1];

    vector<pair<int, int>> edges = {
        {1, 2},
        {1, 3},
        {2, 4},
        {3, 4},
        {3, 5},
        {4, 6},
        {5, 6},
        {5, 7},
        {6, 7},
        {7, 8}
    };

    for (auto edge : edges)
    {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start = 1;
    int goal = 8;
    int max_depth = 7;

    vector<int> path = iddfs_goal(n, adj, start, goal, max_depth);

    if (!path.empty())
    {
        cout << "Path from " << start << " to " << goal << ": ";
        for (int x : path)
            cout << x << " ";
        cout << "\n";
    }
    else
    {
        cout << "Goal not found within depth " << max_depth << "\n";
    }

    return 0;
}
