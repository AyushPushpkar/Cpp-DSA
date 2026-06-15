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

// Beam Search (Width-Limited Best-First)
// Expands only the best 'beam_width' nodes at each level using heuristic h(n)
vector<int> beamSearch(int n, vector<int> adj[], int start, int goal, int h[], int beam_width)
{
    vector<int> parent(n + 1, -1);
    // parent[i] stores the previous node of i (used for path reconstruction)

    vector<int> vis(n + 1, 0);
    // vis[i] = 1 means node i is already visited

    bool found = false;
    // ✅ GOAL FOUND FLAG

    vector<int> current_level;
    current_level.push_back(start);
    // Start from the start node

    vis[start] = 1;
    // Mark start as visited

    while (!current_level.empty())
    {
        vector<int> candidates;
        // Stores all next-level generated nodes

        for (int node : current_level)
        {
            if (node == goal)
            {
                found = true; // ✅ GOAL CONFIRMED
                break;
            }

            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    vis[it] = 1;
                    // Mark neighbor as visited

                    parent[it] = node;
                    // Store how we reached this node

                    candidates.push_back(it);
                    // Add to next-level candidate list
                }
            }
        }

        if (found)
            break;

        if (candidates.empty())
            break;
        // Stop if no more expansion is possible

        // Sort candidates based on heuristic value
        sort(candidates.begin(), candidates.end(), [&](int a, int b)
             { return h[a] < h[b]; });

        // Keep only the best 'beam_width' nodes
        if ((int)candidates.size() > beam_width)
            candidates.resize(beam_width);

        current_level = candidates;
        // Move to next selected beam level
    }

    vector<int> path;

    if (!found)
        return path;
    // ✅ return empty path if goal not reached

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

    vector<int> path = beamSearch(n, adj, 1, 10, h, 3);

    cout << "Best First Path: ";
    for (int x : path)
        cout << x << " ";
}
