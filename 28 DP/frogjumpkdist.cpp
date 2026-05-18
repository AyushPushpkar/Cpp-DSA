#include <bits/stdc++.h>
using namespace std;

/*
Problem:
You are given an array `heights` where heights[i] represents the height of the i-th stone.
A frog starts at stone 0 and wants to reach the last stone.

Rules:
- The frog can jump up to `k` steps forward.
- The cost of a jump from stone i to j is abs(heights[j] - heights[i]).

Task:
Return the minimum total cost required to reach the last stone.
*/

long long frogJump(vector<int> &heights, int k)
{
    int n = heights.size();
    if (n <= 1)
        return 0;

    vector<long long> dp(n); // sc : o(n)

    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);

    for (int i = 2; i < n; i++)
    {
        long long minCost = LLONG_MAX;

        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                long long cost = dp[i - j] + abs(heights[i] - heights[i - j]);
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }
    return dp[n - 1];
}

long long MemoHelper(int idx, vector<long long> &memo, vector<int> &heights, int k)
{
    if (idx == 0)
        return 0;
    ;
    if (idx == 1)
        return abs(heights[1] - heights[0]);

    if (memo[idx] != -1) // tc : o(n)
        return memo[idx];

    long long minCost = LLONG_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (idx - i >= 0)
        {
            long long cost = MemoHelper(idx - i, memo, heights, k) + abs(heights[idx] - heights[idx - i]);
            minCost = min(minCost, cost);
        }
    }

    return memo[idx] = minCost;
}

long long frogJumpMemo(vector<int> &heights, int k)
{

    int n = heights.size();
    if (n == 0)
        return 0;
    vector<long long> memo(n + 1, -1);          // sc : o(n)
    return MemoHelper(n - 1, memo, heights, k); // sc : o(n)
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> heights = {15, 4, 1, 14, 15};

    cout << frogJump(heights, 3) << "\n";
    cout << frogJumpMemo(heights, 3) << "\n";

    return 0;
}
