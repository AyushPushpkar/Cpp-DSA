#include<bits/stdc++.h>
using namespace std;

int minCoins( vector<int>&nums , int  target ) {

    int n = nums.size() ;
    if(n==0)return 0 ; 

    vector<int>prev (target+1,0) ,  curr (target+1,0);

    for(int t=0 ; t<=target ; t++) {
        if (t% nums[0] == 0) prev[t] = t/nums[0] ; 
        else prev[t] = 1e9 ;
    }

    for(int idx = 1 ; idx <n ; idx++){
        for(int w =0 ; w <= target ; w++ ){
            int notpick = prev[w] ;
            int pick = INT_MAX ;
            if(nums[idx] <= w) pick = 1 + curr[w-nums[idx]] ;

            curr[w] = min(notpick , pick) ; 
        }
        prev = curr ; 
    }
    
    int ans = prev[target] ;

    if(ans >= 1e9) return -1 ;

    return ans;
    
}

int minCoinsTab(vector<int>&nums , int  target ) {

    int n = nums.size() ;
    if(n==0)return 0 ; 

    vector<vector<int>>dp (n , vector<int>(target+1,0)) ;

    for(int t=0 ; t<=target ; t++) {
        if (t% nums[0] == 0) dp[0][t] = t/nums[0] ; 
        else dp[0][t] = 1e9 ;
    }

    for(int idx = 1 ; idx <n ; idx++){
        for(int w =0 ; w <= target ; w++ ){
            int notpick = dp[idx-1][w] ;
            int pick = INT_MAX ;
            if(nums[idx] <= w) pick = 1 + dp[idx][w-nums[idx]] ;

            dp[idx][w] = min(notpick , pick) ; 
        }
    }
    
    int ans = dp[n-1][target] ;

    if(ans >= 1e9) return -1 ;

    return ans;
}

// tc : exponential
// sc : o(target)
int minCoinsHelper(vector<int>&nums , int idx ,int target  , vector<vector<int>>&dp) {

    if(target == 0) return 0 ;

    if (idx == 0) {
        if (target >= nums[0] && target% nums[0] == 0) return target/nums[0] ;
        else return 1e9;
    }

    if(dp[idx][target] != -1 ) return dp[idx][target] ;

    int notpick = minCoinsHelper(nums , idx-1 , target , dp ) ;
    int pick = INT_MAX ;
    if(nums[idx] <= target) pick = 1 +  minCoinsHelper(nums ,  idx , target - nums[idx] , dp ) ;

    return dp[idx][target] = min(notpick , pick ) ; 
}


int minCoinsMemo(vector<int>&nums , int  target){

    int n = nums.size() ;
    if(n==0)return 0 ; 

    vector<vector<int>>dp (n , vector<int>(target+1,-1)) ;

    int ans = minCoinsHelper(nums , n-1 , target ,dp ) ;

    if(ans >= 1e9) return -1 ;

    return ans;

}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    vector<int>nums = {9,5,6,1 } ;
    cout << minCoinsMemo(nums , 11) << endl ;
    cout << minCoinsTab(nums , 11) << endl ;
    cout << minCoins(nums , 11) << endl ;
}