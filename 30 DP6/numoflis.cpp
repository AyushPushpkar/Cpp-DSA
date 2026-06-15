#include <bits/stdc++.h>
using namespace std;
/*
Problem:
print Longest inc subsequence 
*/

int findNumberOfLIS(vector<int>& nums) {

    int n = nums.size();

    vector<int> dp(n, 1);
        vector<int> cnt(n, 1);

    int maxi = 1;

    for (int idx = 0; idx < n; idx++) {

        for (int prev = 0; prev < idx; prev++) {

            if (nums[prev] < nums[idx] &&
                dp[idx] < dp[prev] + 1) {

                dp[idx] = dp[prev] + 1;
                cnt[idx] = cnt[prev];
            }
            else if (nums[prev] < nums[idx] &&
                dp[idx] == dp[prev] + 1) {

                cnt[idx] += cnt[prev];
            }
        }

        maxi = max(maxi, dp[idx]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == maxi)    ans += cnt[i];
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums =  { 10 , 9 , 2, 5 , 3, 7 , 101 , 18} ; 

    cout <<  findNumberOfLIS(nums) ;

    return 0;
}
