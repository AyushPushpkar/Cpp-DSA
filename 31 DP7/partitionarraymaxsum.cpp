#include <bits/stdc++.h>
using namespace std;
/*
Given an integer array arr, partition the array into (contiguous) subarrays of length 
at most k. After partitioning, each subarray has their values changed to become the 
maximum value of that subarray.

Return the largest sum of the given array after partitioning. 
Test cases are generated so that the answer fits in a 32-bit integer.
*/


int cutStickTab(int n, vector<int>& cuts){
    int cutSz = cuts.size() ;
    cuts.push_back(n) ;
    cuts.insert(cuts.begin() , 0) ;
    sort(cuts.begin() , cuts.end()) ;

    vector<vector<int>> dp(n , vector<int> (n , 0)) ;

    for(int start = cutSz ; start >= 1 ; start--){
        for(int end = start ; end <= cutSz ; end++){
            int mini = INT_MAX;
            for(int k = start ; k <=end ; k++){
                int cost = cuts[end + 1]  - cuts[start -1] +
                        dp[start][k-1]  + dp[k + 1][ end];

                mini = min(mini, cost);
            }
            dp[start][end] = mini ; 
        }
    }

    return dp[1][cutSz];
     
}

int findMin(int i, int n, vector<int>& arr , vector<int>& memo , int k) {

    if (i == n) return 0;

    if(memo[i] != -1 ) return memo[i] ; 
 
    long long maxi = LLONG_MIN;
    int currMax = 0 ; 

    for (int j = i; j < n; j++) {
        currMax = max(currMax, arr[j]);

        if(j-i +1 <= k) {
            long long sum = (j-i+1)*currMax + findMin(j+1, n ,arr , memo, k) ;
            maxi = max(maxi, sum);
        }
    }

    return memo[i] = (int)maxi;
}

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size() ;
    vector<int> memo(n , -1) ;

    return findMin(0 , n , arr , memo , k) -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = { 5,6,1,4,2 } ; 

    cout << maxSumAfterPartitioning( nums , 2) <<endl ; 
    return 0;
}
