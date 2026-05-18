#include <bits/stdc++.h>
using namespace std;

/*
Problem:
You are given an array `money` where money[i] represents the amount of money
in the i-th house.

Rules:
- You cannot rob two adjacent houses (security system constraint).
- If you rob house i, you must skip house i-1 and i+1.

Task:
Return the maximum amount of money that can be robbed without
robbing any two adjacent houses.
*/


//? max sum of non adjacent nodes
long long houseRobberOptimal(vector<int> &money)
{

    int n = money.size();
    if (n == 1)
        return money[0];
    if (n == 2)
        return max(money[0], money[1]);

    int prev1 = money[0];
    int prev2 = 0;

    long long curr = LLONG_MIN;

    for (int i = 1; i < n; i++)
    {
        long long skip = prev1;
        long long take = money[i] + prev2;

        curr = max(skip, take);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

long long houseRobber(vector<int> &money)
{

    int n = money.size();
    if (n == 1)
        return money[0];
    if (n == 2)
        return max(money[0], money[1]);

    vector<int> dp(n + 1);

    dp[1] = money[0];
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        long long skip = dp[i];
        long long take = money[i] + dp[i - 1];

        dp[i + 1] = max(skip, take);
    }

    return dp[n];
}

long long memoHelper(int idx, vector<int> &money, vector<long long> &memo)
{
    if (idx == 0)
        return money[idx];
    if (idx < 0)
        return 0;

    if (memo[idx] != -1) // tc : o(n)
        return memo[idx];

    long long skip = memoHelper(idx - 1, money, memo);
    long long take = money[idx] + memoHelper(idx - 2, money, memo);

    return memo[idx] = max(skip, take);
}

long long houseRobberMemo(vector<int> &money)
{
    int n = money.size();
    vector<long long> memo(n + 1, -1);

    if (n == 1)
        return money[0];
    if (n == 2)
        return max(money[0], money[1]);

    return memoHelper(n - 1, money, memo);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {2, 1, 4, 9};

    cout << houseRobberOptimal(nums) << "\n";
    cout << houseRobber(nums) << "\n";
    cout << houseRobberMemo(nums) << "\n";

    return 0;
}
