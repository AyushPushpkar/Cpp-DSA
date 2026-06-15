#include<bits/stdc++.h>
using namespace std ;
/*
Problem:
Partition array into two subsets minimizing sum difference.
*/

// TC: O(n × sum) | SC: O(sum)
/*
Problem:
You are given an array `nums` and you need to partition it into two subsets.

Rules:
- Pick elements to form two non-overlapping subsets.
- Compute the absolute difference between their total sums.

Task:
Return the minimum possible subset sum difference.
*/

vector<int> subsetsum(int n  , vector<int> &nums , int target ){

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

    return prev ; 

}

int partitionMinSumDiff(vector<int> & nums){
    int n = nums.size() ;

    if(n== 0 ) return false ;

    int sum = 0 ; 
    for(int i =0 ; i<n ; i++){
        sum += nums[i] ; 
    }

    vector<int>prev = subsetsum(n , nums , sum) ;

    int mini = INT_MAX ; 

    for(int s = 0 ; s<=sum/2 ;s++){
        if(prev[s] == 1) mini = min(mini , abs((sum - s) - s)) ; 
    }

    return mini ; 
    
}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    vector<int>nums = {8 , 2 , 5 , 9 } ;
    cout << partitionMinSumDiff(nums) << endl ;

}