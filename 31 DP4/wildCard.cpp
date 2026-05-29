#include <bits/stdc++.h>
using namespace std;

bool wildcardMatchingSpaceOpt(string s, string p) {
    int n = s.length();
    int m = p.length();

    vector<bool> prev(m + 1, false), curr(m + 1, false);

    prev[0] = true;
    
    for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*') {
            prev[j] = prev[j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        curr[0] = false;

        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                curr[j] = prev[j - 1];
            }
            else if (p[j - 1] == '*') {
                curr[j] = curr[j - 1] || prev[j];
            }
            else {
                curr[j] = false;
            }
        }

        prev = curr;
    }

    return prev[m];
}

bool wildcardMatchingTab(string s, string p) {
    int n = s.length();
    int m = p.length();

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    dp[0][0] = true;

    // empty string can match only all-star pattern
    for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            }
            else {
                dp[i][j] = false;
            }
        }
    }

    return dp[n][m];
}

bool allStars(int j, string &p) {
    for (int k = 0; k <= j; k++) {
        if (p[k] != '*') return false;
    }
    return true;
}

bool matchMemo(int i, int j, string &s, string &p, vector<vector<int>> &memo) {
    if (i < 0 && j < 0) return true;
    if (j < 0) return false;

    // string finished, pattern should contain only '*'
    if (i < 0) return allStars(j, p);

    if (memo[i][j] != -1) return memo[i][j];

    bool ans = false;

    if (s[i] == p[j] || p[j] == '?') {
        ans = matchMemo(i - 1, j - 1, s, p, memo);
    }
    else if (p[j] == '*') {
        ans = matchMemo(i, j - 1, s, p, memo) ||
              matchMemo(i - 1, j, s, p, memo);
    }

    return memo[i][j] = ans;
}

bool wildcardMatchingMemo(string s, string p) {
    int n = s.length();
    int m = p.length();

    vector<vector<int>> memo(n, vector<int>(m, -1));

    return matchMemo(n - 1, m - 1, s, p, memo);
}