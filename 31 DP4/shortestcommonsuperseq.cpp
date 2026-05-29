#include <bits/stdc++.h>
using namespace std;
/*
Problem:
Shortest common supersequence - shortest string containing both as subsequences.
*/

// TC: O(m × n) | SC: O(m × n)
class Solution {
private:
    vector<vector<int>> lcs(int n, int m, string &s1, string &s2) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp;
    }

public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp = lcs(n, m, str1, str2);

        string ans = "";

        int i = n, j = m;

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans.push_back(str1[i - 1]);
                i--;
                j--;
            } 
            else if (dp[i - 1][j] >= dp[i][j - 1]) {
                ans.push_back(str1[i - 1]);
                i--;
            } 
            else {
                ans.push_back(str2[j - 1]);
                j--;
            }
        }

        while (i > 0) {
            ans.push_back(str1[i - 1]);
            i--;
        }

        while (j > 0) {
            ans.push_back(str2[j - 1]);
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str1 = "groot";
    string str2 = "brute";

    Solution obj;

    string ans = obj.shortestCommonSupersequence(str1, str2);

    cout << ans << endl;

    return 0;
}