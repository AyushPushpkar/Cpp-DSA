#include <bits/stdc++.h>
using namespace std ;
/*
Problem:
Minimum path sum in triangle (can move to adjacent bottom elements).
*/

// TC: O(n²) | SC: O(n)
/*
Problem:
You are given a `triangle` array representing a triangle of numbers.

Rules:
- You can only move to adjacent numbers on the row below.

Task:
Return the minimum path sum from the top of the triangle to the base.
*/

//* Fixed Start , varying end 
//* min part sum to reach last layer 
//? can move from {i,j} to {i , j+1 } or {i+1 , j+1}

int triangleOptimal(vector<vector<int>> &triangle ){

    int n = triangle.size() ; 
    if(n==0 ) return 0  ;
    if (n==1) return triangle[0][0] ; 

    vector<vector<int>> dp(n , vector<int>(n,INT_MAX)) ;

    dp[0][0] = triangle [0][0] ;

    for(int i =0 ; i<n ; i++){
        for(int j = 0 ; j<= i ; j++){
            if(i==0 && j==0)continue; 

            // Left edge
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            }
            // Right edge
            else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            }
            // Middle cells
            else {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
            } 
        }
    }

    int ans = dp[n - 1][0]; 

    for(int k = 0 ; k <n ; k++){
        ans = min(ans , dp[n-1][k]) ; 
    }

    return ans ; 
}

int triangleHelper(vector<vector<int>> & triangle ,  int i , int j , vector<vector<int>> &dp){

    if(i == triangle.size() -1) return triangle[i][j] ; 

    if(dp[i][j] != -1) return dp[i][j] ; 

    int down = triangleHelper(triangle , i+1 , j , dp) + triangle[i][j] ;
    int diagonal = triangleHelper(triangle , i+1 , j+1 , dp) + triangle[i][j] ; 

    return dp[i][j] = min(down , diagonal) ; 
}

int triangleMemo(vector<vector<int>> &triangle ){
    int n = triangle.size() ; 

    if (n==1) return triangle[0][0] ; 

    vector<vector<int>> dp(n , vector<int>(n,-1)) ; 

    int ans = triangleHelper(triangle , 0 , 0 , dp ) ; 

    return ans ; 
}



int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    vector<vector<int>> triangle = {
        {1} ,
        {4,3} , 
        {3,5,2} ,
        {8, 1 ,9 ,4 }
    } ;

    cout << triangleMemo(triangle) << endl ; 
    cout  << triangleOptimal (triangle) << endl ;
}