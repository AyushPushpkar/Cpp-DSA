#include <bits/stdc++.h>
using namespace std;

//? tc : O(n^3)
// Multisource shortest path (Floyd-Warshall)

void floyd(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 1e9; // treat -1 as infinity
            }
            if (i == j)
                matrix[i][j] = 0;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][k] < 1e9 && matrix[k][j] < 1e9) // avoid overflow
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    // detect negative cycle
    for (int j = 0; j < n; j++)
    {
        if (matrix[j][j] < 0)
            cout << "Negative cycle detected!\n";
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1e9)
            {
                matrix[i][j] = -1; // convert infinity back to -1
            }
        }
    }
}

int main()
{
    // Example graph: 4 nodes
    // -1 means no edge
    vector<vector<int>> matrix = {
        {0,   3,  -1,  7},
        {-1,  0,   1,  8},
        {-1, -1,   0,  2},
        {-1, -1,  -1,  0}
    };

    floyd(matrix);

    cout << "All-pairs shortest path matrix:\n";
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            cout << setw(4) << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
