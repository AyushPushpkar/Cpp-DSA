#include <bits/stdc++.h>
using namespace std;
/*
Problem:
Count number of ways to climb n stairs (can climb 1 or 2 steps per move).
*/

// TC: O(n) | SC: O(n) [DP array] or O(1) [space optimized]
/*
Problem:
You are climbing a staircase. It takes n steps to reach the top.

Rules:
- Each time you can either climb 1 or 2 steps.

Task:
In how many distinct ways can you climb to the top?
*/

long long climbingStairs(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;

    long long prev2 = 1; // dp[i-2]
    long long prev1 = 1; // dp[i-1]
    long long curr;

    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1; // holds dp[n]
}

long long MemoHelper(int idx, vector<long long> &memo)
{
    if (idx == 0)
        return 1;
    if (idx == 1)
        return 1;

    if (memo[idx] != -1) // tc : o(n)
        return memo[idx];

    long long left = MemoHelper(idx - 1, memo);
    long long right = MemoHelper(idx - 2, memo);
    return memo[idx] = left + right;
}

long long climbingStairsMemo(int n)
{
    vector<long long> memo(n + 1, -1); // sc : o(n)
    return MemoHelper(n, memo);        // sc : o(n)
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << climbingStairs(n) << "\n";
    cout << climbingStairsMemo(n) << "\n";

    return 0;
}
