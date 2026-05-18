#include<bits/stdc++.h>
using namespace std;

/*
Problem:
You are given an array `nums` and a `target` sum.

Rules:
- Identify subsets of `nums` where elements add up to `target`.

Task:
Return the total count of such subsets.
*/

int countSubsetSum(vector<int>&nums , int target ) {

    int n = nums.size() ;
    if(n==0)return 0 ;   
    if( n ==1 ) return target == nums[0] ;

    vector<int> prev (target+1,0) ;
    vector<int> curr (target+1,0) ;

    // prev[0] = curr[0] = 1 ;
    // if(nums[0] <= target) prev[nums[0]] = 1 ;

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

int countSubsetSumTab(vector<int>&nums , int target ) {

    int n = nums.size() ;

    if(n==0)return 0 ;
    if( n ==1 ) return target == nums[0] ;

    vector<vector<int>>dp (n , vector<int>(target+1,0)) ;

    // for(int i = 0 ; i <n ; i++) dp[i][0] = 1 ;
    // if(nums[0] <= target) dp[0][nums[0]] = 1 ;

    if(nums[0] == 0  ) dp[0][0] = 2 ;
    else dp[0][0] = 1 ;

    if(nums[0] != 0 && nums[0] <= target) dp[0][nums[0]] = 1 ;

    for(int idx = 1 ; idx < n ; idx++){
        for(int j = 0 ; j<= target; j++){
            int notpick = dp[idx-1][j] ;
            int pick = 0 ;
            if(nums[idx] <= j) pick = dp[idx-1 ][j-nums[idx] ] ;

            dp[idx][j] =  notpick + pick ; 
        }
    }

    return dp[n-1][target] ;
    
}

int countSubsetSumHelper(vector<int>&nums ,int idx ,int target  , vector<vector<int>>&dp) {

    // if(target == 0) return 1;
    // if(idx == 0) return (target == nums[0]) ;

    if(idx == 0){
        if(target == 0 && nums[0] == 0) return 2 ; 
        else if(target == 0 || target == nums[0]) return 1 ;
        return 0 ; 
    }

    if(dp[idx][target] != -1 ) return dp[idx][target] ;

    int notpick = countSubsetSumHelper(nums , idx-1 , target , dp ) ;
    int pick = 0 ;
    if(nums[idx] <= target) pick = countSubsetSumHelper(nums , idx-1 , target-nums[idx] , dp ) ;

    return dp[idx][target] =  notpick + pick ; 
    
}


int countSubsetSumMemo(vector<int>&nums , int  target){

    int n = nums.size() ;
    if(n==0)return 0 ; 

    vector<vector<int>>dp (n , vector<int>(target+1,-1)) ;

    return countSubsetSumHelper(nums ,n-1 , target ,dp ) ;

}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    vector<int>nums = {8 , 2 , 1 , 3 , 3 , 4 , 5 } ;
    cout << countSubsetSumMemo(nums , 6) << endl ;
    cout << countSubsetSumTab(nums , 6) << endl ;
    cout << countSubsetSum(nums , 6) << endl ;
}