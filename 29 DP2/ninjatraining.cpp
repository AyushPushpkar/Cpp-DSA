#include <bits/stdc++.h>
using namespace std;
/*
Problem:
Ninja training - max points selecting non-consecutive task types each day.
*/

// TC: O(n) | SC: O(n)
/*
Problem:
A ninja has to do exactly one activity each day out of a 2D array `matrix`.

Rules:
- The ninja cannot perform the same activity on two consecutive days.

Task:
Return the maximum points the ninja can earn after `n` days.
*/

//? 2D DP

//tc : O(n*4*3)
//sc : O(4)
int ninjaTraningOptimal(vector<vector<int>> &matrix)
{

    int m = matrix[0].size();
    int n = matrix.size();

    vector<int> prev(m + 1, 0);

    for (int last = 0; last <= m; last++)
    {
        int maxi = INT_MIN;
        for (int j = 0; j < m; j++)
        {
            if (last != m && j == last)
                continue;
            maxi = max(maxi, matrix[0][j]);
        }
        prev[last] = maxi;
    }

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(m+1,0) ; 
        for (int last = 0; last <= m; last++)
        {
            int maxi = 0;
            for (int j = 0; j < m; j++)
            {
                if (last != m && j == last)
                    continue;
                int point = matrix[i][j] + prev[j];
                maxi = max(maxi, point);
            }
            curr[last] = maxi;
        }
        prev = curr ; 
    }

    return prev[m];
}

int ninjaTraning(vector<vector<int>> &matrix)
{

    int m = matrix[0].size();
    int n = matrix.size();

    vector<vector<int>> dp(n, vector<int>(m + 1, 0));

    for (int last = 0; last <= m; last++)
    {
        int maxi = INT_MIN;
        for (int j = 0; j < m; j++)
        {
            if (last != m && j == last)
                continue;
            maxi = max(maxi, matrix[0][j]);
        }
        dp[0][last] = maxi;
    }

    for (int i = 1; i < n; i++)
    {
        for (int last = 0; last <= m; last++)
        {
            int maxi = 0;
            for (int j = 0; j < m; j++)
            {
                if (last != m && j == last)
                    continue;
                int point = matrix[i][j] + dp[i - 1][j];
                maxi = max(maxi, point);
            }
            dp[i][last] = maxi;
        }
    }

    return dp[n - 1][m];
}

int memoHelper(int idx, vector<vector<int>> &matrix, vector<vector<int>> &memo, int last, int n, int m)
{
    int points = 0;

    if (memo[idx][last] != -1)
        return memo[idx][last];

    int maxi = INT_MIN;

    for (int k = 0; k < m; k++)
    {
        if (last != m && k == last) // skip only if last != m
            continue;
        if (idx == 0)
            points = matrix[idx][k];
        else
            points = matrix[idx][k] + memoHelper(idx - 1, matrix, memo, k, n, m);

        maxi = max(maxi, points);
    }

    return memo[idx][last] = maxi;
}

int ninjaTrainingMemo(vector<vector<int>> &matrix)
{
    int m = matrix[0].size();
    int n = matrix.size();
    vector<vector<int>> memo(n, vector<int>(m + 1, -1)); // sc : o(n)  + o(n*4)
    int last = m;

    return memoHelper(n - 1, matrix, memo, last, n, m); // tc : o(n * 4 * 3)
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example 2-D matrix (n rows x m cols)
    vector<vector<int>> matrix = {
        {10, 40, 70},
        {20, 50, 180},
        {30, 60, 90}};

    cout << ninjaTraning(matrix) << endl;
    cout << ninjaTrainingMemo(matrix) << endl;
    cout << ninjaTraningOptimal(matrix) << endl;

    return 0;
}
