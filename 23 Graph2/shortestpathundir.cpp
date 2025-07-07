#include<bits/stdc++.h>
using namespace std ;

/*
*          
*    1——–2——–3——–4
*        |   |   |\             
*        8   7——–5—6
*       / 
*      9   0
*
*/        

vector<int> shortestpathDAC(int n , vector<vector<int>> adj  ,int src){

    queue<int> q ; 

    vector<int> dis (n , INT_MAX) ; 
    dis[src] = 0;

    q.push(src) ;

    while(!q.empty()){  // tc : o(n) + o(2m)
        int node = q.front()  ;
        q.pop() ;

        for(auto it : adj[node]){
            if(dis[node] + 1 < dis[it]){
                dis[it] = 1 + dis[node] ; 

                q.push(it ) ;
            }
        }
    }

    vector<int> ans(n , -1) ;

    for(int i =0 ; i< n ; i++){
        if(dis[i] != INT_MAX) ans[i] = dis[i] ;
    }
        
    return ans ;
}

int main(){
    int n = 10; // number of vertices

    // define adjacency list for nodes 0 to n
    vector<vector<int>> adj(n);

    vector<pair<int, int>> edges = {
        {1, 2},
        {2, 3}, 
        {3, 4},
        {3, 7},
        {4, 5}, 
        {4, 6},
        {6, 5}, 
        {7, 5},
        {8, 2},
        {8, 9},
        // {9, 0},
        // {0, 8}
    };

    // populate adjacency list
    for (auto edge : edges) {
        int u = edge.first ;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u) ;
    }  
    
    vector<int> ans = shortestpathDAC(n , adj , 1  ) ;

    for (int i=0 ; i<n ; i++){
        cout << i << " " << ans[i]  << endl  ; 
    }

    return 0 ;
}