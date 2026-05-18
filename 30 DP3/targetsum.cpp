#include<bits/stdc++.h>
using namespace std;

int countPartitionDiff(vector<int>&nums , int diff ,int totsum , int n ) {  

    if(totsum -diff <0 || (totsum -diff)%2) return false ; 

    int target = (totsum - diff)/2 ; 

    vector<int> prev (target+1,0) ;
    vector<int> curr (target+1,0) ;

    if(nums[0] == 0 ) prev[0] = 2 ;
    else prev[0] = 1 ;
    
    if( nums[0] != 0 && nums[0] <= target) prev[nums[0]] = 1 ;

    for(int idx = 1 ; idx < n ; idx++){
        for(int j =0 ; j<= target; j++){
            int notpick = prev[j] ;
            int pick = 0 ;
            if(nums[idx] <= j) pick = prev[j-nums[idx] ] ;

            curr[j] =  notpick + pick ; 
        }
        prev = curr ; 
    }

    return prev[target] ;
    
}

int targetSum(vector<int>&nums , int  target){
    int n = nums.size() ;

    if(n== 0 ) return 0 ;

    int total = accumulate(nums.begin(), nums.end(), 0);

    if(abs(target) > total) return 0;

    return countPartitionDiff(nums , target ,total , n) ;
}

int helper(vector<int>& nums, int idx, int target, vector<vector<int>>& dp, int offset) {

    if(idx == 0) {
        int ways = 0;
        if(target == nums[0]) ways++;
        if(target == -nums[0]) ways++;
        return ways;
    }

    if(dp[idx][target + offset] != -1)
        return dp[idx][target + offset];

    int pos = helper(nums, idx - 1, target - nums[idx], dp, offset);
    int neg = helper(nums, idx - 1, target + nums[idx], dp, offset);

    return dp[idx][target + offset] = pos + neg;
}

int targetSumMemo(vector<int>& nums, int target) {
    int n = nums.size();
    int total = accumulate(nums.begin(), nums.end(), 0);

    if(abs(target) > total) return 0;

    vector<vector<int>> dp(n, vector<int>(2 * total + 1, -1));

    return helper(nums, n - 1, target, dp, total);
}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    vector<int>nums = {1,2,3,1 } ;
    cout << targetSumMemo(nums , 3) << endl ;
    cout << targetSum(nums , 3) << endl ;
}