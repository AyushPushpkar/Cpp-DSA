#include <bits/stdc++.h>
using namespace std ;
/*
Problem:
Maximum path sum falling through grid (diagonal/adjacent allowed).
*/

// TC: O(rows × cols) | SC: O(rows × cols)
/*
Problem:
You are given an n x m `grid` of integers.

Rules:
- A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right.

Task:
Return the minimum/maximum sum of any falling path through `grid`.
*/

int minFallingPathSum(vector<vector<int>>& grid) {
        
    int n = grid.size() ;
    int m = grid[0].size() ;

    if(m==0 or n == 0 ) return 0 ;

    vector<vector<int>> dp( n, vector<int>(m , 0)) ;

    for(int j =0 ; j<m ;j++){
        dp[0][j] = grid[0][j] ;
    } 

    for(int i = 1 ; i<n ;i++){
        for(int j =0 ;j<m ;j++){
            
            int up = dp[i-1 ][j] ;
            int left = j>0 ? dp[i-1 ][ j-1]  : INT_MAX ; 
            int right = j< grid[0].size()-1 ? dp[i-1][j+1 ] : INT_MAX; 
 
            dp[i][j] = min(up,min(left,right))  + grid[i][j]; 
        }
    }

    int ans = dp[n - 1][0]; 

    for(int k = 0 ; k <n ; k++){
        ans = min(ans , dp[n-1][k]) ; 
    }

    return ans ; 
}

int maxPath(vector<vector<int>> &grid){
    int n = grid.size() ;
    int m = grid[0].size() ;

    if(m==0 or n == 0 ) return 0 ;

    vector<vector<int>> dp( n, vector<int>(m , 0)) ;

    for(int i =0 ; i<m ;i++){
        dp[0][i] = grid[0][i] ;
    } 

    for(int i = 0 ; i<n ;i++){
        for(int j =0 ;j<m ;j++){
            if(i==0 ) continue;
            
            int up = dp[i-1 ][j] ;
            int left = j>0 ? dp[i-1 ][ j-1]  : INT_MIN ; 
            int right = j< grid[0].size()-1 ? dp[i-1][j+1 ] : INT_MIN; 
 
            dp[i][j] = max(up,max(left,right))  + grid[i][j]; 
        }
    }

    int ans = dp[n - 1][0]; 

    for(int k = 0 ; k <n ; k++){
        ans = max(ans , dp[n-1][k]) ; 
    }

    return ans ; 
}

int maxPathHelper(int i , int j , vector<vector<int>> &PathGrid , vector<vector<int>> &dp ){

    if(i ==0 ) return dp[0][j] = PathGrid[0][j]; ;

    if(dp[i][j] != -1) return dp[i][j] ; 

    int up = maxPathHelper(i-1 , j , PathGrid , dp) ;
    int left = j>0 ? maxPathHelper(i-1 , j-1 , PathGrid , dp)  : INT_MIN ; 
    int right = j<PathGrid[0].size()-1 ? maxPathHelper(i-1 , j+1 , PathGrid , dp) : INT_MIN; 

    return dp[i][j] = max(up , max(left , right)) + PathGrid[i][j] ; 
}

int maxPathMemo(vector<vector<int>> &pathGrid){
                                                                                                                                                               
    int n = pathGrid.size() ;
    int m = pathGrid[0].size() ;

    if(m==0 or n == 0 ) return 0 ;

    int maxp = INT_MIN ; 
    vector<vector<int>> dp( n, vector<int>(m , -1)) ;
    for(int i =0 ; i < m ; i++) {
        
        maxp = max(maxp , maxPathHelper(n-1 , m-1-i , pathGrid , dp)) ; 
    }

    return maxp ; 

}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    vector<vector<int>> pathGrid = {
        {5 , 9 , 6 , 5} ,
        {11, 5 , 2 , 70} ,
        {1 , 3 , 30 , 1} ,
        {100 , 6 ,7 ,2}
    } ;

    cout << maxPathMemo(pathGrid) << endl ; 
    cout << maxPath(pathGrid) <<endl ;
    cout << minFallingPathSum(pathGrid) << endl ;
}