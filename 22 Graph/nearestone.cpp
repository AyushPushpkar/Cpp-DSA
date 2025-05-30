#include<bits/stdc++.h>
using namespace std ;

void bfstraversal( queue<pair<pair<int,int>,int>> &q ,vector<vector<int>> &newgrid , vector<vector<int>> &grid){

    int n = grid.size() ;
    int m = grid[0].size() ;

    int delrow[] = { -1, 0 ,1  , 0} ;
    int delcol[] = {0 , -1 , 0 , 1} ;

    while(!q.empty()){  

        pair<pair<int,int>,int> node = q.front();
        int row = node.first.first , col = node.first.second ;
        int dist = node.second ;
        q.pop() ;

        for(int i = 0 ; i<4 ; i++){
            int neighrow = row+delrow[i] ;
            int neighcol = col+delcol[i] ; 

            if(neighrow >= 0 && neighrow < n && neighcol >=0 && neighcol <m){
                if( newgrid[neighrow][neighcol] == 0  && grid[neighrow][neighcol] == 0){
                    newgrid[neighrow][neighcol] = dist+1 ;
                    q.push({{neighrow,neighcol}, dist+1}) ;    
                }
            }
        
        }
    }

}

vector<vector<int>> nearestone( vector<vector<int>> &grid){   // tc : o(n*m) + o(n*m*4)
    int n = grid.size() ;
    int m = grid.at(0).size() ;

    vector<vector<int>> newgrid = grid ; // sc : o(n*m)

    queue<pair<pair<int,int>,int>> q ;  // sc :  o(n*m)

    for(int i=0 ;i<n ;i++){   // tc : o(n*m)
        for (int j=0 ; j<m ;j++){
            if(grid[i][j] == 1 && newgrid[i][j] != 0){
                newgrid[i][j] = 0 ; 
                q.push({{i,j},0}) ;
            }
        }
    }

    bfstraversal(q  , newgrid , grid) ;

    return newgrid ;
}

int main(){

    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},  
        {0, 0, 0, 0, 1}, 
        {0, 0, 1, 0, 0},  
        {0, 0, 1, 0, 0}
    };

    vector<vector<int>> ans = nearestone(grid) ; ;
    
    for(auto it : ans){
        for(int itt : it){
            cout << itt << " " ;
        }cout << endl ; 
    }

    return 0 ;
}