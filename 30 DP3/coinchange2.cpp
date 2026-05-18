#include<bits/stdc++.h>
using namespace std;

int coinChange( vector<int>&coins , int  amount ) {

    int n = coins.size();
    if(n == 0) return 0;

    vector<int>prev (amount+1,0) ,  curr (amount+1,0);

    const int MOD = INT_MAX;

    prev[0] = curr[0] = 1;

    for(int t = 0; t <= amount; t++) {
        if(coins[0] != 0 && t % coins[0] == 0)
            prev[t] = 1;
    }

    for(int idx = 1; idx < n; idx++) {
        for(int w = 0; w <= amount; w++) {

            int notpick = prev[w];
            int pick = 0;

            if(coins[idx] <= w)
                pick = curr[w - coins[idx]];

            curr[w] = ( (long long)pick + notpick ) % MOD;
        }

        prev = curr ;
    }

    return prev[amount];
    
}

int coinChangeTab(vector<int>&coins , int  amount ) {

    int n = coins.size();
    if(n == 0) return 0;

    const int MOD = 1e10;

    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    for(int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    for(int t = 0; t <= amount; t++) {
        if(coins[0] != 0 && t % coins[0] == 0)
            dp[0][t] = 1;
    }

    for(int idx = 1; idx < n; idx++) {
        for(int w = 0; w <= amount; w++) {

            int notpick = dp[idx - 1][w];
            int pick = 0;

            if(coins[idx] <= w)
                pick = dp[idx][w - coins[idx]];

            dp[idx][w] = ( (long long)pick + notpick ) % MOD;
        }
    }

    return dp[n - 1][amount];

}

int coinChangeHelper(vector<int>&nums , int idx ,int target  , vector<vector<int>>&dp) {

    if(target == 0) return 1 ;

    if (idx == 0) {
        if (target >= nums[0] && target% nums[0] == 0) return 1 ;
        else return 0;
    }

    if(dp[idx][target] != -1 ) return dp[idx][target] ;

    int notpick = coinChangeHelper(nums , idx-1 , target , dp ) ;
    int pick = 0 ;
    if(nums[idx] <= target) pick = coinChangeHelper(nums ,  idx , target - nums[idx] , dp ) ;

    return dp[idx][target] = notpick + pick ; 
}


int coinChangeMemo(vector<int>&nums , int  target){

    int n = nums.size() ;
    if(n==0)return 0 ; 

    vector<vector<int>>dp (n , vector<int>(target+1,-1)) ;

    int ans = coinChangeHelper(nums , n-1 , target ,dp ) ;

    if(ans >= 1e9) return -1 ;

    return ans;

}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    vector<int>nums = {1,2,3,4 } ;
    cout << coinChangeMemo(nums , 4) << endl ;
    cout << coinChangeTab(nums , 4) << endl ;
    cout << coinChange(nums , 4) << endl ;
}