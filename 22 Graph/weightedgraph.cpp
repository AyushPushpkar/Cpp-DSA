#include<bits/stdc++.h>
using namespace std ;

int matrixGraph(int n , int m) {
    int adj[n+1][n+1] ;  // space : o(n^2)
    
    for(int i = 0 ; i < m ; i++){
        int u , v , w;
        cin >> u >> v ;
        adj[u][v] = w ;
        adj[v][u] = w ;
    } 

    return 0 ;
}

int listGraph(int n , int m) {
    vector<pair<int, int>> adj[n + 1];  // space: O(2m) for undirected graph

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  // because the graph is undirected
    }

    return 0 ;
}

int main(){
    int n , m ;
    cin >> n >> m ;
    

    return 0 ;
}