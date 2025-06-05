#include<bits/stdc++.h>
using namespace std ;

void dfstraversal(int row , int col ,vector<vector<int>> &grid ,vector<vector<int>> &vis ){

    int n = grid.size() ;
    int m = grid[0].size() ;

    vis[row][col] = 1 ;

    int delrow[] = { -1, 0 ,1  , 0} ;
    int delcol[] = {0 , -1 , 0 , 1} ;

    for(int i= 0 ; i <4  ; i ++){
        int neighrow = row+delrow[i] ;
        int neighcol = col + delcol[i]; 

        if(neighrow >= 0 && neighrow < n && neighcol >=0 && neighcol <m){
            if( !vis[neighrow][neighcol]  && grid[neighrow][neighcol] == 0){
                dfstraversal(neighrow,neighcol ,vis ,  grid  ) ;
            }
        }

    }

}

vector<vector<int>> surroundedRegion( vector<vector<int>> &grid){   // tc : o(n) + o(m) + o(n*m*4)
    int n = grid.size() ;
    int m = grid.at(0).size() ;

    vector<vector<int>> newgrid = grid ; // sc : o(n*m)

    vector<vector<int>> vis(n , vector<int>(m , 0)) ;  // sc :  o(n*m)

    for(int i=0 ;i<n ;i++){   
        if(grid[i][0]==0 && vis[i][0]!= 1 )
        dfstraversal( i , 0 ,vis , grid) ;  
        
        if(grid[i][m-1] == 0 && vis[i][m-1] != 1)
        dfstraversal(i , m-1 ,vis ,  grid) ;
    }

    for(int j=0 ;j<m ;j++){   
        if(grid[0][j]==0 && vis[0][j]!= 1 )
        dfstraversal( 0 , j ,vis , grid) ;  
        
        if(grid[n-1][j] == 0 && vis[n-1][j] != 1)
        dfstraversal(n-1 , j ,vis , grid) ;
    }

    for(int i= 0 ; i<n ;i++){
        for(int j=0 ; j< m ;j++){
            if(!vis[i][j] && grid[i][j] == 0){
                newgrid[i][j] = 1;
            }
        }
    }

    return newgrid ;
}

int main(){

    vector<vector<int>> grid = {
        {1, 1, 1, 1, 0},  
        {1, 0, 0, 0, 1}, 
        {1, 0, 1, 1, 1},  
        {1, 1, 1, 0, 0}
    };

    vector<vector<int>> ans = surroundedRegion(grid) ; ;
    
    for(auto it : ans){
        for(int itt : it){
            cout << itt << " " ;
        }cout << endl ; 
    }

    return 0 ;
}