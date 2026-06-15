#include <bits/stdc++.h>
using namespace std;
/*
Problem:
Longest inc subsequence 
*/

//tle 
int lisubsequenceOptimal(vector<int>& nums) {
    int n = nums.size();

    vector<int> ahead(n + 1, 0);
    vector<int> curr(n + 1, 0);

    for (int idx = n - 1; idx >= 0; idx--) {
        for (int prev = idx - 1; prev >= -1; prev--) {

            int len = ahead[prev + 1];  // not take

            if (prev == -1 || nums[idx] > nums[prev]) {
                len = max(len, 1 + ahead[idx + 1]); // take
            }

            curr[prev + 1] = len;
        }

        ahead = curr;
    }

    return ahead[0];
}

int lisubsequenceTab(vector<int>& nums) {
    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int idx = n - 1; idx >= 0; idx--) {
        for (int prev = idx - 1; prev >= -1; prev--) {

            int len = dp[idx + 1][prev + 1]; // not take

            if (prev == -1 || nums[idx] > nums[prev]) {
                len = max(len, 1 + dp[idx + 1][idx + 1]); // take
            }

            dp[idx][prev + 1] = len;
        }
    }

    return dp[0][0]; // prev = -1, so prev + 1 = 0
}

int lisubsequenceHelper(int idx, int prev  , vector<int> &nums ,vector<vector<int>> &memo ){
    
    if (idx  == nums.size())
        return 0;

    if (memo[idx][prev+1] != -1)
        return memo[idx][prev+1];

    int  len =  lisubsequenceHelper(idx + 1, prev, nums, memo);

    if(prev == -1 || nums[idx] >nums[prev]) 
        len = max (len , 1+ lisubsequenceHelper(idx +1 ,idx , nums , memo )) ; 
        
    return memo[idx][prev+1] = len ; 
}

int lisubsequenceMemo(vector<int> &nums){

    int n = nums.size() ;
    vector<vector<int>> memo(n, vector<int>(n+1, -1));
    return lisubsequenceHelper(0 , -1, nums,  memo);     
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums =  { 10 , 9 , 2, 5 , 3, 7 , 101 , 18} ; 

    cout << lisubsequenceMemo(nums) << endl ;
    cout << lisubsequenceTab(nums) << endl ;
    cout << lisubsequenceOptimal(nums) << endl ;

    return 0;
}
