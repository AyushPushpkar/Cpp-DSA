#include<bits/stdc++.h>
using namespace std ;

int bfstraversal( queue<pair<pair<int,int>,int>> &q ,vector<vector<int>> &newgrid , vector<vector<int>> &grid){

    int n = grid.size() ;
    int m = grid[0].size() ;

    int delrow[] = { -1, 0 ,1  , 0} ;
    int delcol[] = {0 , -1 , 0 , 1} ;

    int mintime = 0 ;

    while(!q.empty()){  

        pair<pair<int,int>,int> node = q.front();
        int row = node.first.first , col = node.first.second ;
        int time = node.second ;
        q.pop() ;

        for(int i = 0 ; i<4 ; i++){
            int neighrow = row+delrow[i] ;
            int neighcol = col+delcol[i] ; 

            if(neighrow >= 0 && neighrow < n && neighcol >=0 && neighcol <m){
                if( newgrid[neighrow][neighcol] != 2  && grid[neighrow][neighcol] == 1){
                    newgrid[neighrow][neighcol] = 2 ;
                    q.push({{neighrow,neighcol}, time+1}) ;    
                    mintime = time + 1 ;
                }
            }
        
        }
    }

    return mintime ;
}

int rottingoranges( vector<vector<int>> &grid){  // tc : o(n*m) + o(n*m*4)
    int n = grid.size() ;
    int m = grid.at(0).size() ;

    vector<vector<int>> newgrid = grid ; // sc : o(n*m)

    queue<pair<pair<int,int>,int>> q ;  // sc :  o(n*m)

    for(int i=0 ;i<n ;i++){
        for (int j=0 ; j<m ;j++){
            if(grid[i][j] == 2 ){
                q.push({{i,j},0}) ;
            }
        }
        
    }

    int mintime = bfstraversal(q , newgrid , grid) ;

    for(int i=0 ;i<n ;i++){
        for (int j=0 ; j<m ;j++){
            if(newgrid[i][j] == 1 ){
                return -1 ;
            }
        }
    }

    return mintime ;
}

int main(){

    // 0 -> empty
    // 1 -> fresh 
    // 2 -> rotten

    vector<vector<int>> grid = {
        {1, 1, 2 , 1},  
        {1, 2, 0 , 1},  
        {2, 0, 2 , 1}
    };

    int time = rottingoranges(grid) ;
    
    cout << time << " unit time" << endl ; 

    return 0 ;
}