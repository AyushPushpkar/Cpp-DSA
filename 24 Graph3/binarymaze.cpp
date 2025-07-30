#include<bits/stdc++.h>
using namespace std ;     

//shortest dist in a binary  maze

//! no negative weight
//? tc : o(ElogV)

int binaryMaze( vector<vector<int>> maze  ,pair<int,int> src , pair<int,int> dst){
    int n = maze.size() ;
    int m = maze.at(0).size();

    queue<pair<int , pair<int, int>>> q ; 

    vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
    dis[src.first][src.second] = 0;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    q.push({0, src}) ;

    while(!q.empty()){  // tc : o(n) + o(2m)
        pair<int,int> node = q.front().second  ;
        int x = node.first ;
        int y = node.second ;
        int dist = q.front().first ;
        q.pop() ;

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if(dis[x][y] + 1 < dis[nx][ny] && maze[nx][ny] == 1){
                    dis[nx][ny] = 1 + dis[x][y] ;
                    if(nx == dst.first && ny == dst.second) return dis[nx][ny] ; 
                    q.push({dis[x][y] , {nx,ny}}) ;
                }
            }
        }
    }
        
    return -1 ;
}

int main(){

    vector<vector<int>> maze = {
        {0, 1, 1, 1},
        {0, 1, 0, 1},
        {0, 1, 1, 1},
        {1, 1, 0, 0},
        {0, 0, 1, 0}
    };
  
    
    int ans = binaryMaze(maze , {0,1}  ,  {3,0}) ;

    cout << ans  << endl  ;

    return 0 ;
}