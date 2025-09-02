#include<bits/stdc++.h>
using namespace std ;     

//shortest dist in a binary  maze

//! no negative weight
//? tc : o(ElogV)

int minEffort( vector<vector<int>> &heights ){
    int n = heights.size() ;
    int m = heights.at(0).size();

    priority_queue<pair<int , pair<int, int>>, vector<pair<int , pair<int, int>>>, greater<pair<int , pair<int, int>>>> pq_min ;

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[0][0] = 0;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    pq_min.push({0, {0,0}}) ;

    while(!pq_min.empty()){  
        pair<int, int> node = pq_min.top().second  ;
        int x = node.first ;
        int y = node.second ;
        int diff = pq_min.top().first ;
        pq_min.pop() ;

        if(x == n-1 && y == m-1) return diff ; 

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                int newEffort = max(abs(heights[x][y]- heights[nx][ny]) , diff) ;
                if(newEffort < dist[nx][ny]){
                    dist[nx][ny] = newEffort ;
                    pq_min.push({newEffort , {nx , ny}}) ; 
                }
            }
        }
    }
        
    return 0 ;
}

int main(){

    vector<vector<int>> heights = {
        {1,2,2},
        {3,8,2},
        {5,3,5}
    };

    int n = heights.size() ;
    int m = heights.at(0).size();
  
    int ans = minEffort(heights) ;

    cout << ans ;

    return 0 ;
}