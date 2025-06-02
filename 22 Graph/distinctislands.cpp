#include<bits/stdc++.h>
using namespace std ;

void dfstraversal(int row , int col ,vector<vector<int>> &grid ,vector<vector<int>> &vis ,
    vector<pair<int,int>> &island ,int basex , int basey){

    int n = grid.size() ;
    int m = grid[0].size() ;

    vis[row][col] = 1 ;
    island.push_back({row - basex,col - basey}) ;

    int delrow[] = { -1, 0 ,1  , 0} ;
    int delcol[] = {0 , -1 , 0 , 1} ;

    for(int i= 0 ; i <4  ; i ++){
        int neighrow = row+delrow[i] ;
        int neighcol = col + delcol[i]; 

        if(neighrow >= 0 && neighrow < n && neighcol >=0 && neighcol <m){
            if( !vis[neighrow][neighcol]  && grid[neighrow][neighcol] == 1){
                dfstraversal(neighrow,neighcol ,  grid , vis , island , basex , basey ) ;
            }
        }

    }

}

int distinctislands( vector<vector<int>> &grid){   // tc : o(n*m*log(n*m)) + o(n*m*4)
    int n = grid.size() ;
    int m = grid.at(0).size() ;
    int unique = 0 ;

    vector<vector<int>> vis(n , vector<int>(m , 0)) ;  // sc :  o(n*m)

    set<vector<pair<int,int>>> location ; // sc :  o(n*m)

    for(int i=0 ;i<n ;i++){
        for (int j=0 ; j<m ;j++){
            if(!vis[i][j] && grid[i][j] ==1 ){

                vector<pair<int,int>> island ; 
                dfstraversal(i,j , grid, vis, island , i , j) ;
                
                location.emplace(island) ; // log(n*m)
            }
        }
        
    }

    unique = location.size() ; 

    return unique ;
}

// num of islands that are distinct

int main(){

    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1},    //1 -> land cell 
        {1, 0, 0, 0, 1},    //0 -> sea cell
        {0, 0, 0, 0, 0},  
        {0, 1, 0, 1, 1},
        {0 ,1 ,0 ,1 ,0}
    };

    int ans = distinctislands(grid) ; ;
    
    cout << ans << endl ;

    return 0 ;
}