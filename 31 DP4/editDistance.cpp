#include <bits/stdc++.h>
using namespace std;
/*
Problem:
Edit distance (Levenshtein) - minimum operations to transform one string to another.
*/

// TC: O(m × n) | SC: O(m × n)
class Solution {
public:

    int minDistanceSpaceOpt(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);

        for (int j = 0; j <= m; j++) prev[j] = j;

        for (int i = 1; i <= n; i++) {
            curr[0] = i;

            for (int j = 1; j <= m; j++) {

                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1];
                } 
                else {
                    int replace = 1 + prev[j - 1];
                    int remove  = 1 + prev[j];
                    int insert  = 1 + curr[j - 1];

                    curr[j] = min(replace, min(remove, insert));
                }
            }

            prev = curr;
        }

        return prev[m];
    }

    int minDistanceTab(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int j = 0; j <= m; j++) dp[0][j] = j;

        for (int i = 0; i <= n; i++) dp[i][0] = i;
        

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                
                else {
                    int replace = 1 + dp[i - 1][j - 1];
                    int remove  = 1 + dp[i - 1][j];
                    int insert  = 1 + dp[i][j - 1];

                    dp[i][j] = min(replace, min(remove, insert));
                }
            }
        }

        return dp[n][m];
    }

    int editDistanceHelper(int i, int j, string &s1, string &s2,
                           vector<vector<int>> &memo) {

        if (i < 0) return j + 1;
        if (j < 0) return i + 1;

        if (memo[i][j] != -1) return memo[i][j];

        if (s1[i] == s2[j]) {
            return memo[i][j] = editDistanceHelper(i - 1, j - 1, s1, s2, memo);
        }

        int replace = 1 + editDistanceHelper(i - 1, j - 1, s1, s2, memo);
        int remove  = 1 + editDistanceHelper(i - 1, j, s1, s2, memo);
        int insert  = 1 + editDistanceHelper(i, j - 1, s1, s2, memo);

        return memo[i][j] = min(replace, min(remove, insert));
    }

    int minDistanceMemo(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> memo(n, vector<int>(m, -1));

        return editDistanceHelper(n - 1, m - 1, word1, word2, memo);
    }
};

int main() {
    string word1 = "horse";
    string word2 = "ros";

    Solution obj;

    cout << "Memoization: " << obj.minDistanceMemo(word1, word2) << endl;
    cout << "Tabulation: " << obj.minDistanceTab(word1, word2) << endl;
    cout << "Space Optimized: " << obj.minDistanceSpaceOpt(word1, word2) << endl;

    return 0;
}