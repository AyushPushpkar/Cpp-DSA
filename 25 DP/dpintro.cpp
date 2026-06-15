#include <bits/stdc++.h>
using namespace std;
/*
Problem:
Dynamic Programming fundamentals and introduction.
*/

// TC: O(n) | SC: O(n)
// Those who cannot remember past are condemned to repeat it.
//? Dynamic Programming remembers past results to avoid recomputation.

// count the no of ways
// min , max
// try all possible ways  - best , cnt

//* try to represent problem in terms of index
//* do all possible steps on that index , acc to problem statement
//* cnt all ways  - sum of all stuffs
//* find min - min of all stuffs

// Example: Fibonacci using DP (Tabulation)
// Bottom up
long long fibonacciDP(int n)
{
    // base cases
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    vector<long long> dp(n + 1); // sc : o(n)
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) // tc : o(n)
    {
        dp[i] = dp[i - 1] + dp[i - 2]; // use previously computed results
    }
    return dp[n];
}

// Example: Fibonacci using DP (Memoization)
// Top dowm
long long fibMemoHelper(int n, vector<long long> &memo)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (memo[n] != -1) // tc : o(n)
        return memo[n];
    return memo[n] = fibMemoHelper(n - 1, memo) + fibMemoHelper(n - 2, memo);
}

long long fibonacciMemo(int n)
{
    vector<long long> memo(n + 1, -1); // sc : o(n)
    return fibMemoHelper(n, memo);     // sc : o(n) recursion stack space
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter n for Fibonacci: ";
    cin >> n;

    cout << "Fibonacci(" << n << ") using Tabulation = " << fibonacciDP(n) << "\n";
    cout << "Fibonacci(" << n << ") using Memoization = " << fibonacciMemo(n) << "\n";

    return 0;
}
