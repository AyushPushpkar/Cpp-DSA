#include <bits/stdc++.h>
using namespace std ;
/*
Problem:
Minimum path sum in m×n grid (move right or down only).
*/

// TC: O(rows × cols) | SC: O(rows × cols)
/*
Problem:
You are given a matrix `grid` with non-negative numbers.

Rules:
- You can move either down or right at any point in time.

Task:
Return the minimum path sum from the top-left to the bottom-right.
*/

int minPath(vector<vector<int>> &grid){
    int n = grid.size() ;
    int m = grid[0].size() ;

    if(m==0 or n == 0 ) return 0 ;

    vector<vector<int>> dp( n, vector<int>(m , 0)) ;

    dp[0][0] = grid[0][0] ; 

    for(int i = 0 ; i<n ;i++){
        for(int j =0 ;j<m ;j++){
            if(i==0 && j== 0 ) continue;
            
            int up = i>0 ? dp[i-1][j] + grid[i][j] : INT_MAX;
            int left = j>0 ? dp[i][j-1] + grid[i][j] : INT_MAX ; 

            dp[i][j] = min(up,left) ; 
        }
    }

    return dp[n-1][m-1] ;
}

int minPathHelper(int i , int j , vector<vector<int>> &PathGrid , vector<vector<long long>> &dp ){

    if(i ==0 && j== 0 ) return dp[0][0] = PathGrid[0][0]; ;

    if(dp[i][j] != -1) return dp[i][j] ; 

    long long up = i>0 ? minPathHelper(i-1 , j , PathGrid , dp) + PathGrid[i][j] : LLONG_MAX;
    long long left = j>0 ? minPathHelper(i , j-1 , PathGrid , dp) + PathGrid[i][j] : LLONG_MAX ; 

    return dp[i][j] = min(up , left) ; 
}

int minPathMemo(vector<vector<int>> &pathGrid){

    int n = pathGrid.size() ;
    int m = pathGrid[0].size() ;

    if(m==0 or n == 0 ) return 0 ;

    vector<vector<long long>> dp( n, vector<long long>(m , -1)) ; 

    return minPathHelper(n-1 , m-1 , pathGrid , dp) ;

}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    vector<vector<int>> pathGrid = {
        {5 , 9 , 6} ,
        {11, 5 , 2}
    } ;

    cout << minPathMemo(pathGrid) << endl ; 
    cout << minPath(pathGrid) <<endl ;
}