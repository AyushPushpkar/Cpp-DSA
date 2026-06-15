#include <bits/stdc++.h>
using namespace std;
/*
Given a wooden stick of length n units. The stick is labelled from 0 to n. 

Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.
You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the 
sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks 

Return the minimum total cost of the cuts.
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

//? cost = n*m*p

int findMin(int start, int end, vector<int>& cuts , vector<vector<int>>& memo) {

    if (start > end) return 0;

    if(memo[start][end] != -1 ) return memo[start][end] ; 
 
    int mini = INT_MAX;

    for (int k = start; k <= end; k++) {

        int cost = cuts[end + 1]  - cuts[start -1] + 
                        findMin(start, k+1, cuts , memo) + findMin(k + 1, end, cuts , memo);

        mini = min(mini, cost);
    }

    return memo[start][end] = (int)mini;
}

int cutStickMemo(int n, vector<int>& cuts) {
        int cutSz = cuts.size() ;
        cuts.push_back(n) ;
        cuts.insert(cuts.begin() , 0) ;
        sort(cuts.begin() , cuts.end()) ; 

        vector<vector<int>> memo(cutSz + 2 , vector<int> (cutSz + 2 , -1)) ;

        return findMin(1 , cutSz , cuts , memo) ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = { 5,6,1,4,2 } ; 

    cout << cutStickMemo( 9, nums) <<endl ; 
    return 0;
}
