#include<bits/stdc++.h>
using namespace std ;

void dfstraversal(int row , int col ,vector<vector<int>> &grid , vector<vector<int>> &newgrid ,
    int newcolor , int inicolor , int delrow[] , int delcol[] ){

    int n = grid.size() ;
    int m = grid[0].size() ;

    newgrid[row][col] = newcolor ; 

    for(int i= 0 ; i <4  ; i ++){
        int neighrow = row+delrow[i] ;
        int neighcol = col + delcol[i]; 

        if(neighrow >= 0 && neighrow < n && neighcol >=0 && neighcol <m){
            if(newgrid[neighrow][neighcol] != newcolor && grid[neighrow][neighcol] == inicolor){
                dfstraversal(neighrow,neighcol , grid , newgrid, newcolor , inicolor , delrow , delcol) ;
            }
        }

    }

}

// tc : o(n*m) + o(n*m*4)
vector<vector<int>> floodfill( vector<vector<int>> &grid , int sr , int sc , int newcolor){  

    vector<vector<int>> newgrid = grid ;  // sc : O(n*m)

    int inicolor = grid[sr][sc] ; 

    int delrow[] = { -1, 0 ,1  , 0} ;
    int delcol[] = {0 , -1 , 0 , 1} ;

    dfstraversal(sr,sc , grid , newgrid, newcolor , inicolor , delrow , delcol) ;  // sc : : O(n*m)   stack space

    return newgrid ;
}

int main(){
    
    int sr = 2 , sc = 0 ;
    int newcolor = 3; 

    vector<vector<int>> grid = {
        {1, 1, 1},  
        {2, 2, 0},  
        {2, 2, 2}
    };

    vector<vector<int>> ans = floodfill(grid , sr , sc , newcolor) ;
    
    for(auto it : ans){
        for(int itt : it){
            cout << itt << " " ;
        }cout << endl ; 
    }

    return 0 ;
}