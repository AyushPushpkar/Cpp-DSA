#include <bits/stdc++.h>
using namespace std ;
/*
Problem:
Unique paths in m×n grid (move right or down only).
*/

// TC: O(rows × cols) | SC: O(rows × cols)
/*
Problem:
There is a robot on an m x n grid.

Rules:
- The robot can only move down or right.

Task:
Return the number of possible unique paths to reach the bottom-right corner.
*/

int uniquePaths(int m ,int n ){

    if(m<=0 || n <=0 )return 0 ;
    if(m ==1 && n==1) return 1 ; 
     
    vector<vector<int>> dp( m , vector<int>(n,0)) ; 

    for (int i = 0 ; i < m ; i++) dp[i][0] =1 ;

    for(int j = 1; j< n ; j++) dp[0][j] =1 ;    

    for (int i = 1 ; i < m ; i++){
        for(int j = 1; j< n ; j++){

            dp[i][j] = dp[i-1][j] + dp[i][j-1] ; 
        }
    }

    return dp[m-1][n-1] ; 

}

int uniquePathHelper(int m ,int  n , vector<vector<int>> dp){

    if(m<=0 || n <=0 )return 0 ;
    if(m ==1 && n==1) return 1 ;  

    if(dp[m-1][n-1] != -1) return dp[m-1][n-1] ; 

    int cntup = uniquePathHelper(m , n-1 , dp ) ;
    int cntleft = uniquePathHelper( m-1 ,  n , dp) ; 
    
    return dp[m-1][n-1] = cntup + cntleft  ; 
}

int uniquePathsMemo(int m , int n){

    int cnt = 0 ;
    vector<vector<int>> dp( m , vector<int>(n,-1)) ; 
    cnt = uniquePathHelper(m , n , dp) ; 

    return cnt ;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr) ; 

    int m , n ; 

    cin >> m >> n ; 

    cout << uniquePathsMemo(3 , 3) << endl ;
    cout << uniquePaths(3 , 3) << endl ;

    return 0 ;
}
