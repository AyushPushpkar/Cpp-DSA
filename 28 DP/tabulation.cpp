#include <bits/stdc++.h>
using namespace std;

// Problem: Fibonacci number using Tabulation approach.

long long fibonacciOptimised(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    long long prev2 = 0; // dp[i-2]
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter n for Fibonacci: ";
    cin >> n;

    cout << "Fibonacci(" << n << ") using space-optimised Tabulation = "
         << fibonacciOptimised(n) << "\n";

    return 0;
}
