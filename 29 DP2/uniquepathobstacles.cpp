#include <bits/stdc++.h>
using namespace std ;
/*
Problem:
Unique paths in m×n grid with obstacles.
*/

// TC: O(rows × cols) | SC: O(rows × cols)
/*
Problem:
There is a robot on an m x n `obstacleGrid` with obstacles.

Rules:
- The robot can only move down or right.
- It cannot step on obstacle cells.

Task:
Return the number of possible unique paths to reach the bottom-right corner avoiding obstacles.
*/

int uniquePaths(vector<vector<int>> &obstacleGrid ){

    int n = obstacleGrid.size() ;
    int m = obstacleGrid[0].size() ;

    if(m<=0 || n <=0 )return 0 ;
    if (obstacleGrid[0][0] == -1 || obstacleGrid[n-1][m-1] == -1)return 0;
     
    vector<vector<long long>> dp( n , vector<long long>(m,0)) ; 

        dp[0][0] = 1 ;    

        for (int i = 0 ; i < n ; i++){
            for(int j = 0; j< m ; j++){

                if (obstacleGrid[i][j] == 1) continue;

                if(i==0 && j==0 ) continue;

                long long up = (i > 0) ? dp[i-1][j] : 0;
                long long left = (j > 0) ? dp[i][j-1] : 0;
                
                dp[i][j] = up + left ; 
           }
       }

       return dp[n-1][m-1] ; 

}

int uniquePathHelper(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &pathGrid){

    if(i<0 || j<0 )return 0 ;
    if(i>=0 && j>=0 && pathGrid[i][j] == -1) return 0 ; 
    if(i==0 && j==0) return 1 ;  

    if(dp[i][j] != -1) return dp[i][j] ; 

    int cntleft = uniquePathHelper(i, j-1 , dp , pathGrid) ;
    int cntup = uniquePathHelper( i-1 ,  j , dp , pathGrid) ; 
    
    return dp[i][j] = cntup + cntleft ; 
}

int uniquePathsMemo(vector<vector<int>> &matrix){

    int n = matrix.size();
    int m = matrix[0].size();

    int cnt = 0;

    if(m <= 0 || n <= 0) return 0;
    if(n == 1 && m == 1 && matrix[0][0] == -1) return cnt;

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cnt = uniquePathHelper(n-1, m-1, dp, matrix);

    return cnt;
}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    vector<vector<int>> matrix = {
        {0 , 0 , 0 } ,
        {0 , -1 , 0 },
        {0, 0 , 0 }
    } ; 

    cout << uniquePathsMemo(matrix) << endl ;
    cout << uniquePaths(matrix) << endl ;  
}