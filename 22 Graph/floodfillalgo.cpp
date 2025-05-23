#include<bits/stdc++.h>
using namespace std ;

void bfstraversal( int row , int col ,vector<vector<int>> &vis , vector<vector<int>> &grid){

    int n = grid.size() ;
    int m = grid[0].size() ;

    vis[row][col] = 1 ;

    queue<pair<int,int>> q ;  // sc :  o(n^2)
    q.push({row,col}) ;

    while(!q.empty()){  
        pair<int,int> node = q.front();
        int row = node.first , col = node.second ;
        q.pop() ;

        for(int delrow = -1 ; delrow<= 1 ;delrow++){
            for (int delcol= -1  ; delcol<= 1 ; delcol++){
                int neighrow = row+delrow ;
                int neighcol = col+delcol ; 

                if(neighrow >= 0 && neighrow < n && neighcol >=0 && neighcol <m){
                    if(!vis[neighrow][neighcol] && grid[neighrow][neighcol] == 1){
                        vis[neighrow][neighcol] = 1 ;
                        q.push({neighrow,neighcol}) ;
                    }
                }
            }
        
        }
    }

}

int numislands( vector<vector<int>> &grid){  // tc : o(n^2)
    int n = grid.size() ;
    int m = grid.at(0).size() ;

    int cnt = 0 ;
    vector<vector<int>> vis(n,vector<int>(m , 0)) ; // sc : o(n^2)

    for(int i=0 ;i<n ;i++){
        for (int j=0 ; j<m ;j++){
            if(!vis[i][j] && grid[i][j] ==1 ){
                bfstraversal(i,j , vis , grid) ;  
                cnt++ ;
            }
        }
        
    }

    return cnt ;
}

int main(){

    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},  // Island 1
        {0, 0, 0, 0, 1},  // Island 3
        {0, 0, 1, 0, 0},  // Island 2
        {0, 0, 1, 0, 0}
    };

    int ans = numislands(grid) ;
    
    cout << ans << endl ; 

    return 0 ;
}