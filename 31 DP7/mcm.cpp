#include <bits/stdc++.h>
using namespace std;
/*
Problem:
Matrix Chain Multiplication

min operations/cost to multiply 
*/

int mcmTab(vector<int> &nums){
    int n = nums.size() ;

    if(n <=  2) return 0 ; 
    vector<vector<int>> dp(n , vector<int> (n , 0)) ;

    for(int i = 1 ; i< n ; i++){
        dp[i][i] = 0 ; 
    }

    for(int start = n-1 ; start >= 1 ; start--){
        for(int end = start+1 ; end < n ; end++){
            long long minMul = LLONG_MAX;
            for(int k = start ; k <end ; k++){
                long long steps = 1LL * nums[start - 1] * nums[k] * nums[end] + 
                        dp[start][k]  + dp[k + 1][ end];

                minMul = min(minMul, steps);
            }
            dp[start][end] = (int)minMul ; 
        }
    }

    return dp[1][n - 1];
     
}

//? cost = n*m*p

int findMin(int start, int end, vector<int>& nums , vector<vector<int>>& memo) {

    if (start == end) return 0;

    if(memo[start][end] != -1 ) return memo[start][end] ; 

    long long minMul = LLONG_MAX;

    for (int k = start; k < end; k++) {

        long long steps = 1LL * nums[start - 1] * nums[k] * nums[end] + 
                        findMin(start, k, nums , memo) + findMin(k + 1, end, nums , memo);

        minMul = min(minMul, steps);
    }

    return memo[start][end] = (int)minMul;
}

int mcmMEMO(vector<int> &nums){
    int n = nums.size() ;

    if(n <=  2) return 0 ; 
    vector<vector<int>> memo(n , vector<int> (n , -1)) ;

    return findMin(1 , n-1 , nums , memo) ; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = { 10 , 5 , 20 , 30 , 40 , 50 } ; 

    cout << mcmMEMO(nums) <<endl ; 
    return 0;
}
