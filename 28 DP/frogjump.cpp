#include <bits/stdc++.h>
using namespace std;
/*
Problem:
Frog jump - find minimum jumps to reach end from stairs (can jump 1 or 2 steps).
*/

// TC: O(n) | SC: O(n)
/*
Problem:
You are given an array `heights` where heights[i] represents the height of the i-th stone.
A frog starts at stone 0 and wants to reach the last stone.

Rules:
- The frog can jump either 1 step or 2 steps forward.
- The cost of a jump from stone i to j is abs(heights[j] - heights[i]).

Task:
Return the minimum total cost required to reach the last stone.
*/

// Time: O(n), Space: O(1)
long long frogJump(vector<int> &heights)
{
    int n = heights.size();
    if (n <= 1)
        return 0;

    long long prev2 = 0;
    long long prev1 = abs(heights[1] - heights[0]);
    long long curr = LLONG_MAX;

    for (int i = 2; i < n; i++)
    {

        long long cost1 = prev1 + abs(heights[i] - heights[i - 1]);
        long long cost2 = prev2 + abs(heights[i] - heights[i - 2]);

        curr = min(cost1, cost2);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

// Time: O(n), Space: O(n)
long long MemoHelper(int idx, vector<long long> &memo, vector<int> &heights)
{
    if (idx == 0)
        return 0;
    ;
    if (idx == 1)
        return abs(heights[1] - heights[0]);

    if (memo[idx] != -1) // tc : o(n)
        return memo[idx];

    long long left = MemoHelper(idx - 1, memo, heights) + abs(heights[idx] - heights[idx - 1]);
    long long right = MemoHelper(idx - 2, memo, heights) + abs(heights[idx] - heights[idx - 2]);

    return memo[idx] = min(left, right);
}

long long frogJumpMemo(vector<int> &heights)
{

    int n = heights.size();
    if (n == 0)
        return 0;
    vector<long long> memo(n + 1, -1);       // sc : o(n)
    return MemoHelper(n - 1, memo, heights); // sc : o(n)
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> heights = {7, 5, 1, 2, 6};

    cout << frogJump(heights) << "\n";
    cout << frogJumpMemo(heights) << "\n";

    return 0;
}
