#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();

    vector<vector<int>> dp(n + 1, vector<int>(5, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int trans = 3; trans >= 0; trans--) {

            if (trans % 2 == 0) {
                // buy case
                dp[i][trans] = max(  -prices[i] + dp[i + 1][trans+ 1], dp[i + 1][trans] );
            } 
            else {
                // sell case
                dp[i][trans] = max( prices[i] + dp[i + 1][trans + 1],dp[i + 1][trans]);
            }
        }
    }

    return dp[0][0];
}

// Space optimized DP
int maxProfitSO(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> ahead(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));
    for (int tr = 0; tr < 3; tr++) {
        ahead[0][tr] = ahead[1][tr] = 0;
    }
    for (int buy = 0; buy < 2; buy++) {
        curr[buy][0] = 0;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int tr = 1; tr < 3; tr++) {
            curr[1][tr] = max(-prices[i] + ahead[0][tr], ahead[1][tr]);
            curr[0][tr] = max(prices[i] + ahead[1][tr - 1], ahead[0][tr]);
        }
        ahead = curr;
    }
    return curr[1][2];
}

// Tabulation DP
int maxProfitTab(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(
        n + 1,
        vector<vector<int>>(2, vector<int>(3, 0))
    );
    for (int tr = 0; tr < 3; tr++) {
        dp[n][0][tr] = dp[n][1][tr] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int buy = 0; buy < 2; buy++) {
            dp[i][buy][0] = 0;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int tr = 1; tr < 3; tr++) {
            dp[i][1][tr] = max(-prices[i] + dp[i + 1][0][tr], dp[i + 1][1][tr]);
            dp[i][0][tr] = max(prices[i] + dp[i + 1][1][tr - 1], dp[i + 1][0][tr]);
        }
    }
    return dp[0][1][2];
}

// Memoized recursion
int stock(vector<int>& prices, bool buy, int tr, int i, vector<vector<vector<int>>>& memo) {
    if (i == prices.size()) return 0;
    if (tr == 0) return 0;
    if (memo[i][buy][tr] != -1) return memo[i][buy][tr];
    int profit = 0;
    if (buy) {
        profit = max(
            -prices[i] + stock(prices, false, tr, i + 1, memo),
            stock(prices, true, tr, i + 1, memo)
        );
    } else {
        profit = max(
            prices[i] + stock(prices, true, tr - 1, i + 1, memo),
            stock(prices, false, tr, i + 1, memo)
        );
    }
    return memo[i][buy][tr] = profit;
}

int maxProfitMemo(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> memo(
        n,
        vector<vector<int>>(2, vector<int>(3, -1))
    );
    return stock(prices, true, 2, 0, memo);
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;
    vector<int> prices(n);
    cout << "Enter prices: ";
    for (int i = 0; i < n; ++i) cin >> prices[i];

    cout << "Max Profit (Memoized): " << maxProfitMemo(prices) << endl;
    cout << "Max Profit (Tabulation): " << maxProfitTab(prices) << endl;
    cout << "Max Profit (Space Optimized): " << maxProfitSO(prices) << endl;
    return 0;
}
