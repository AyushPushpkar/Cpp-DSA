#include<bits/stdc++.h>
using namespace std ;

/*
Problem:
You are given an array `nums`.

Rules:
- Check if it can be partitioned into two subsets.
- Both subsets must have equal sums.

Task:
Return true if such an equal partition is possible, false otherwise.
*/

bool subsetsum(int n ,vector<int> &nums , int target ){

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

bool partitionsubset(vector<int>&nums){
    int n = nums.size() ;

    if(n== 0 ) return false ;

    int sum = 0 ; 
    for(int i =0 ; i<n ; i++){
        sum += nums[i] ; 
    }
    if(sum%2 == 1) return false ; 
    else return subsetsum(n , nums , sum/2 ) ; 
}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    vector<int>nums = {8 , 2 , 5 , 9 } ;
    cout << partitionsubset(nums) << endl ;
}