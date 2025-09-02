#include <bits/stdc++.h>
using namespace std;

//? tc : O(n^3)
// Multisource shortest path (Floyd-Warshall)

int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<vector<int>> matrix(n, vector<int>(n, 1e9));

    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int w = it[2];
        matrix[u][v] = w;
        matrix[v][u] = w;
    }

    for (int i = 0; i < n; i++)
        matrix[i][i] = 0;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][k] < 1e9 && matrix[k][j] < 1e9) // avoid overflow
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }

    // Debug print matrix
    cout << "Shortest path matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] >= 1e9)
                cout << "INF ";
            else
                cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    // Count reachable cities
    int ans = -1;
    int minCnt = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j && matrix[i][j] <= distanceThreshold)
            {
                cnt++;
            }
        }
        cout << i << " " << cnt << endl;
        if (cnt <= minCnt)
        { // tie → pick larger index
            minCnt = cnt;
            ans = i;
        }
    }

    return ans;
}

int main()
{
    int n = 8; // Cities 0 to 7
    vector<vector<int>> edges = {
        {0, 1, 3},
        {0, 2, 5},
        {0, 3, 10},
        {1, 2, 2},
        {1, 4, 4},
        {2, 3, 2},
        {2, 5, 8},
        {3, 6, 6},
        {4, 5, 3},
        {4, 7, 7},
        {5, 6, 1},
        {6, 7, 2}};

    int distanceThreshold = 7;

    int city = findTheCity(n, edges, distanceThreshold);

    cout << city << endl;

    return 0;
}