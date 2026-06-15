#include <bits/stdc++.h>
using namespace std;
/*
Problem:
Longest divisble subset 

distinct numbers 
output in any order
*/

void ldsubsetTab(vector<int>& nums, vector<int>& hash, vector<int>& dp) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        hash[i] = i;
    }

    for (int idx = 0; idx < n; idx++) {
        for (int prev = 0; prev < idx; prev++) {

            if ((nums[idx] % nums[prev]) == 0 && dp[idx] < 1 + dp[prev]) {
                dp[idx] = 1 + dp[prev];
                hash[idx] = prev;
            }
        }
    }
}

vector<int> ldsubsetOptimal(vector<int> &nums){

    int n = nums.size() ;
    vector<int> dp(n) ,  hash(n) ;

    sort(nums.begin() , nums.end()) ;

    ldsubsetTab(nums , hash , dp ) ;

    int maxidx = 0 ; 

    for(int  i = 1 ; i< n ; i++){
        if(dp[i] > dp[maxidx]) maxidx = i ; 
    }

    vector<int> ans ; 

    while(hash[maxidx] != maxidx){
        ans.push_back(nums[maxidx]);
        maxidx = hash[maxidx];
    }
    ans.push_back(nums[maxidx]); 

    return ans ; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums =  { 10 , 9 , 2, 5 , 3, 7 , 101 , 18} ; 

    vector<int>ans = ldsubsetOptimal(nums) ;
    for(int i = 0 ; i<ans.size() ; i++){
        cout << ans[i] << " " ; 
    }cout << endl ; 

    return 0;
}
