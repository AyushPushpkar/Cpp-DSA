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

// Hill Climbing (Steepest-Ascent)
// Always moves to the neighbor with strictly smaller heuristic h(n)
vector<int> hillClimbing(int n, vector<int> adj[], int start, int goal, int h[])
{
    vector<int> path;
    // Stores the traversal path

    bool found = false;
    // ✅ GOAL FOUND FLAG

    int curr = start;
    // Current node in search

    path.push_back(curr);
    // Start path from start node

    while (true)
    {
        if (curr == goal)
        {
            found = true;
            // ✅ GOAL CONFIRMED
            break;
        }

        int best_neighbor = -1;
        int best_h = h[curr];
        // Track best downhill move

        for (auto it : adj[curr])
        {
            if (h[it] < best_h)
            {
                best_h = h[it];
                best_neighbor = it;
                // Choose neighbor with lower heuristic
            }
        }

        if (best_neighbor == -1)
            break;
        // ❌ No better neighbor → local optimum reached

        curr = best_neighbor;
        // Move to best downhill neighbor

        path.push_back(curr);
        // Add to path
    }

    if (!found)
        return {};
    // ✅ return empty path if goal not reached (stuck in local minimum)

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

    vector<int> path = hillClimbing(n, adj, 1, 10, h);

    cout << "Best First Path: ";
    for (int x : path)
        cout << x << " ";
}
