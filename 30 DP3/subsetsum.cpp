#include<bits/stdc++.h>
using namespace std ;

/*
Problem:
You are given an array `nums` and a `target` integer.

Rules:
- You can pick elements from `nums` to form a subset.

Task:
Return true if there is a subset that sums exactly to `target`.
*/

bool subsetsumOptimal(vector<int> &nums , int target){
    int n = nums.size() ;

    if(n== 0 ) return false ;
    if( n ==1 ) return target == nums[0] ;

    vector<int> prev(target+1, 0) , curr(target+1  , 0);

    prev[0] = curr[0] = 1 ;
    
    if(nums[0] <= target) prev[nums[0]] = 1;

    for(int idx = 1 ; idx <n ; idx++){
        for(int j = 1 ; j <= target ; j++ ){
            bool skip =  prev[j] ; 
            bool take = false ; 
            if (j >= nums[idx] )  take = prev[j-nums[idx]] ; 

            curr[j] = skip || take ; 
        }
        prev = curr ; 
    }

    return prev[target] ; 

}

bool subsetsumTab(vector<int> &nums , int target){
    int n = nums.size() ;

    if(n== 0 ) return false ;
    if( n ==1 ) return target == nums[0] ;

    vector<vector<int>> dp(n, vector<int>(target+1, 0));

    for(int i = 0 ; i<n ;i++){
        dp[i][0] = 1 ;
    }
    if(nums[0] <= target)
    dp[0][nums[0]] = 1;

    for(int idx = 1 ; idx <n ; idx++){
        for(int j = 1 ; j <= target ; j++ ){
            bool skip =  dp[idx-1][j] ; 
            bool take = false ; 
            if (j >= nums[idx] )  take = dp[idx-1][j-nums[idx]] ; 

            dp[idx][j] = skip || take ; 
        }
    }

    return dp[n-1][target] ; 

}

bool subsetsumHelper(vector<vector<int>> &dp , int idx , int &n , vector<int> &nums , int target){
    if(target == 0 ) return true ; 
    if(idx == 0) return nums[0] == target;

    if(dp[idx][target] != -1) return  dp[idx][target]; 

    bool skip = subsetsumHelper(dp , idx -1 , n , nums , target) ;
    bool take = false ;
    if(target >= nums[idx])take = subsetsumHelper(dp , idx-1  , n , nums , target - nums[idx]) ; 

    return dp[idx][target] = skip || take ; 

}

bool subsetsum(vector<int> &nums , int target){
    int n = nums.size() ;

    if(n== 0 ) return false ;
    if( n ==1 ) return target == nums[0] ;

    vector<vector<int>> dp(n, vector<int>(target+1, -1));

    return subsetsumHelper(dp , n-1 , n , nums , target) ; 
}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    vector<int>nums = {8 , 2 , 5 , 9 } ;
    cout << subsetsum(nums , 11) << endl; 
    cout << subsetsumTab(nums, 4) << endl ;
    cout << subsetsumOptimal(nums, 20) << endl ;
}