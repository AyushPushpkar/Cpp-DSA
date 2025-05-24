#include<bits/stdc++.h>
using namespace std ;

int matrixGraph(int n , int m) {
    int adj[n+1][n+1] ;  // space : o(n^2)
    
    for(int i = 0 ; i < m ; i++){
        int u , v ;
        cin >> u >> v ;
        adj[u][v] = 1 ;
        adj[v][u] = 1 ;
    } 

    return 0 ;
}

int listGraph(int n , int m) {
    vector<int> adj[n+1] ;  // space : o(2m)
    
    for(int i = 0 ; i < m ; i++){
        int u , v ;
        cin >> u >> v ;
        adj[u].push_back(v);
        adj[v].push_back(u) ;
    } 

    return 0 ;
}

int main(){
    int n , m ;
    cin >> n >> m ;
    

    return 0 ;
}