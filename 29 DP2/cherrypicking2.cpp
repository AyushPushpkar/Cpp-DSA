#include <bits/stdc++.h>
using namespace std ;
/*
Problem:
Cherry picking 2 - max sum collecting cherries from top-left to bottom-right and back.
*/

// TC: O(m × n × m) | SC: O(m × n)
/*
Problem: Ninja and His Friends (Chocolate Pickup)

You are given a grid of size N x M where each cell contains some chocolates.

Two ninjas start from the first row:
- Ninja 1 starts at column 0
- Ninja 2 starts at column M-1

Both ninjas move from the top row to the bottom row.

From any cell (i, j), a ninja can move to the next row (i+1) in three possible ways:
    - (i+1, j-1)
    - (i+1, j)
    - (i+1, j+1)

At every step both ninjas move simultaneously.

Rules:
1. When a ninja visits a cell, they collect all chocolates in that cell.
2. If both ninjas land on the same cell, chocolates from that cell are counted only once.
3. Ninjas cannot move outside the grid.

Goal:
Return the maximum number of chocolates both ninjas can collect together by the time they reach the last row.
*/

int ninjaChoco(vector<vector<int>> &grid){
    int n = grid.size() ;
    int m = grid[0].size() ;

    if(m==0 or n == 0 ) return 0 ;
 
    vector<vector<vector<int>>> dp( n, vector<vector<int>>(m , vector<int>(m,0))) ;


    for ( int j1 = 0 ; j1<m ;j1++){
        for (int j2 = 0 ; j2<m ; j2++){
            if(j1 == j2) dp[n-1][j1][j2] = grid[n-1][j1] ;
            else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
        }
    }


    for(int i =n-2 ; i>=0 ; i--){
        for ( int j1 = 0 ; j1<m ;j1++){
            for (int j2 = 0 ; j2<m ; j2++){
                
                int maxi = -1e8 ;  

                for ( int  dj1= -1 ; dj1<=1 ;dj1++){
                    for (int dj2 = -1 ; dj2<=1 ; dj2++){

                        int value = 0 ;

                        if(j1 == j2) value  =   grid[i][j1]  ;
                        else value =   grid[i][j1]+ grid[i][j2] ;

                        if(j1 + dj1 >= 0 && j1 + dj1 <m && j2+dj2>=0 && j2+dj2<m ) 
                        value += + dp[i+ 1][ j1 + dj1][j2+dj2] ; 
                        else value += -1e8 ; 

                        maxi =  max(maxi , value ) ; 
                    }

                }

                dp[i][ j1][j2] = maxi ; 
            }
        }
    }

    return dp[0][0][m-1] ; 
}


//tc recursion = o(3^n + 3^m) exponential
//tc o(n*m*m)*9   sc o(n*m*m)+ o(n)
int ninjaChocoHelper(int &n , int &m , int i, int j1 , int j2 , vector<vector<int>> &PathGrid , vector<vector<vector<int>>> &dp ){

    if( j1 < 0 || j2<0 || j1>=m || j2>=m ) return -1e8 ; 
    
    if(i == n-1 ){
        if(j1== j2) return dp[i][j1][j2] = PathGrid[i][j1] ;
        else return dp[i][j1][j2] = PathGrid[i][j1] + PathGrid[i][j2] ; 
    }

    if(dp[i][j1][j2] != -1 ) return dp[i][j1][j2] ; 

    int maxi =0 ;  

    for ( int k = -1 ; k<=1 ;k++){
        for (int j = -1 ; j<=1 ; j++){
            if(j1 == j2) maxi =  max(maxi , PathGrid[i][j1] + ninjaChocoHelper(n , m , i+ 1 , j1 +k , j2+j  , PathGrid , dp)) ;
            else maxi =  max(maxi , PathGrid[i][j1] + PathGrid[i][j2] + ninjaChocoHelper(n , m , i + 1 , j1 +k, j2+j  , PathGrid , dp)) ;
        }
    }

    

    return dp[i][j1][j2] = maxi ; 
}

int ninjaChocoMemo(vector<vector<int>> &pathGrid){
                                                                                                                                                               
    int n = pathGrid.size() ;
    int m = pathGrid[0].size() ;

    if(m==0 or n == 0 ) return 0 ;
 
    vector<vector<vector<int>>> dp( n, vector<vector<int>>(m , vector<int>(m,-1))) ;
    
    int maxchoco = ninjaChocoHelper(n , m , 0 , 0 , m-1 , pathGrid , dp) ;

    return maxchoco ; 

}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    vector<vector<int>> pathGrid = {
        {5 , 9 , 6 , 5} ,
        {11, 5 , 2 , 70} ,
        {1 , 3 , 100 , 1} ,
        {30 , 6 ,7 ,2}
    } ;

    cout << ninjaChocoMemo(pathGrid) << endl ; 
    cout << ninjaChoco(pathGrid) <<endl ;
}