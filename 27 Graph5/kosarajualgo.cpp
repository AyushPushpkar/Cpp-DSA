#include <bits/stdc++.h>
using namespace std;
/*
Problem:
Kosaraju's algorithm for strongly connected components.
*/

// TC: O(V + E) | SC: O(V)
//?strongly connected components
//* tc : o(V+E)

void dfs(vector<vector<int>> &adj, vector<int> &vis, int startNode, stack<int> &finishOrder)
{

    vis[startNode] = 1;

    for (auto it : adj[startNode])
    {
        int adjNode = it;
        if (!vis[adjNode])
        {
            dfs(adj, vis, adjNode, finishOrder);
        }
    }

    finishOrder.push(startNode);
}

void dfs2(vector<vector<int>> &adj, vector<int> &vis, int startNode)
{

    vis[startNode] = 1;

    for (auto it : adj[startNode])
    {
        int adjNode = it;
        if (!vis[adjNode])
        {
            dfs2(adj, vis, adjNode);
        }
    }
}

int kosaraju(int V, vector<vector<int>> &adj)
{

    vector<int> visited(V, 0);
    stack<int> finishOrder;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            dfs(adj, visited, i, finishOrder);
    }

    vector<vector<int>> newAdj;

    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
        for (auto it : adj[i])
        {
            newAdj[it].push_back(i);
        }
    }

    int sccs = 0;
    while (!finishOrder.empty())
    {
        int node = finishOrder.top();
        finishOrder.pop();

        if (!visited[node])
        {
            sccs++;
            dfs2(newAdj, visited, node);
        }
    }

    return sccs;
}