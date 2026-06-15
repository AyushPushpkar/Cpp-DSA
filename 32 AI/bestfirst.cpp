#include <bits/stdc++.h>
using namespace std;

/*
 *                    1 (S)
 *                  /         \
 *               2 (A)        3 (B)
 *             /      \            \
 *         4 (C)     5 (D)         6 (E)
 *           |         |             |
 *         7 (F)     8 (H)         9 (I)
 *                                      |
 *                                   10 (G)
 *
 ?   GOAL NODE = 10 (G)
 !   TRAP NODE = 7 (F)  → hill climbing fails here
 */

// Greedy Best-First Search
// Selects next node based only on minimum heuristic value h(n)
vector<int> bestFirstSearch(int n, vector<int> adj[], int start, int goal, int h[])
{
    vector<int> parent(n + 1, -1);
    // parent[i] stores the previous node of i (used for path reconstruction)

    vector<int> vis(n + 1, 0);
    // vis[i] = 1 means node i is already visited

    bool found = false; // ✅ GOAL FOUND FLAG

    // Min-heap based on heuristic value (h)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({h[start], start});
    // Push start node with its heuristic value

    vis[start] = 1;
    // Mark start as visited

    while (!pq.empty())
    {
        int node = pq.top().second;
        // Extract node with smallest heuristic value

        pq.pop();

        if (node == goal)
        {
            found = true; // ✅ GOAL CONFIRMED
            break;
        }
        // Stop when goal is reached

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                // Mark neighbor as visited

                parent[it] = node;
                // Store how we reached this node

                pq.push({h[it], it});
                // Push neighbor based on heuristic only
            }
        }
    }

    vector<int> path;

    if (!found)
        return path; // return empty path if goal not reached

    int curr = goal;
    // Start backtracking from goal

    while (curr != -1)
    {
        path.push_back(curr);
        curr = parent[curr];
        // Move backwards using parent[] until start
    }

    reverse(path.begin(), path.end());
    // Reverse to get path from start → goal

    return path;
}

int main()
{
    int n = 10;
    vector<int> adj[n + 1];

    // Graph construction based on the given diagram
    adj[1] = {2, 3};
    adj[2] = {4, 5};
    adj[3] = {6};
    adj[4] = {7};
    adj[5] = {8};
    adj[6] = {9};
    adj[9] = {10};

    // Heuristic values: estimated distance to goal (10)
    int h[11] = {0, 10, 4, 8, 3, 6, 7, 1, 5, 2, 0};

    vector<int> path = bestFirstSearch(n, adj, 1, 10, h);

    cout << "Best First Path: ";
    for (int x : path)
        cout << x << " ";
}
