#include <bits/stdc++.h>
using namespace std;
/*
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with 
a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. 
If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is 
a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.
*/

int burstBalloonsTab(vector<int> &nums){
    int n = nums.size() ;

    if(n == 1) return nums[0] ; 
    vector<vector<int>> dp(n+2 , vector<int> (n+2 , 0)) ;
    nums.push_back(1) ;
    nums.insert(nums.begin() , 1) ;

    for(int start = n-1 ; start >= 1 ; start--){
        for(int end = start+1 ; end < n ; end++){
            long long maxi = LLONG_MIN;
            for(int k = start ; k <=end ; k++){
                long long coins = 1LL * nums[start - 1] * nums[k] * nums[end+1] + 
                        dp[start][k-1]  + dp[k + 1][ end];

                maxi = max(maxi, coins);
            }
            dp[start][end] = (int)maxi ; 
        }
    }

    return dp[1][n];
     
}

//? cost = n*m*p

int findMaxCoins(int start, int end, vector<int>& nums , vector<vector<int>>& memo) {

    if (start > end) return 0;

    if(memo[start][end] != -1 ) return memo[start][end] ; 

    long long maxi = LLONG_MIN;

    for (int k = start; k <=end; k++) {

        long long coins = 1LL * nums[start - 1] * nums[k] * nums[end+1] + 
                        findMaxCoins(start, k-1, nums , memo) + findMaxCoins(k + 1, end, nums , memo);

        maxi = max(maxi, coins);
    }

    return memo[start][end] = (int)maxi;
}

int burstBalloonsMEMO(vector<int> &nums){
    int n = nums.size() ;

    if(n == 1) return nums[0] ; 
    vector<vector<int>> memo(n+2 , vector<int> (n+2 , -1)) ;
    nums.push_back(1) ;
    nums.insert(nums.begin() , 1) ;

    return findMaxCoins(1 , n , nums , memo) ; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = { 3 ,1 , 5, 8 } ; 

    cout << burstBalloonsMEMO(nums) <<endl ; 
    return 0;
}
