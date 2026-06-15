#include <bits/stdc++.h>
using namespace std;
/*
Problem:
print Longest bitonic subsequence 
*/

void lisubsequence(vector<int>& nums, vector<int>& dp) {
    int n = nums.size();

    for (int idx = 0; idx < n; idx++) {
        for (int prev = 0; prev < idx; prev++) {

            if (nums[prev] < nums[idx] && dp[idx] < 1 + dp[prev]) {
                dp[idx] = 1 + dp[prev];
            }
        }
    }

    return  ;
}

int lbsubsequence(vector<int> &nums){

    int n = nums.size() ;
    vector<int> front(n , 1) , back(n , 1) ; 
    
    lisubsequence(nums , front ) ;

    reverse(nums.begin() , nums.end() ) ;
    lisubsequence(nums ,  back ) ;

    int lbs = 1 ; 

    for(int  i = 1 ; i< n ; i++){
        lbs = max(lbs , front[i] + back[n-i-1] -1 ) ; 
    }

    return lbs ; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums =  { 10 , 9 , 2, 5 , 3, 7 , 101 , 18} ; 

    cout <<  lbsubsequence(nums) ;

    return 0;
}
