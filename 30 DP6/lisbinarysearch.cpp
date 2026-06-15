#include <bits/stdc++.h>
using namespace std;
/*
Problem:
Longest inc subsequence 
*/

// tc : o(n*logn)
//sc : o(n)
int lisubsequenceBS(vector<int> &nums){

    int n = nums.size() ;
    vector<int> temp ;
    temp.push_back(nums[0]) ;

    for(int i = 1 ; i < n ; i++){
        if(nums[i] > temp.back()) {
            temp.push_back(nums[i]) ;
        }else{
            int idx = lower_bound(temp.begin(), temp.end(), nums[i]) -temp.begin();
            temp[idx] = nums[i] ;
        }
    }
    return temp.size() ;   
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums =  { 10 , 9 , 2, 5 , 3, 7 , 101 , 18} ; 

    cout << lisubsequenceBS(nums) << endl ;

    return 0;
}
