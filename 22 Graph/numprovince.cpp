#include<bits/stdc++.h>
using namespace std ;

/*
*       1
*      / \
*     2   3
*      \ / 
*       4   5
*          / \
*         6---7
*              
*               8
*/

void dfstraversal( vector<int> adj[] , int startnode , int vis[] ){

    vis[startnode] = 1 ; 

    for(auto it : adj[startnode]){  // degree
        if(!vis[it]){
            dfstraversal(adj,it , vis ) ;
        }
    }

}

int numprovince(int n ,  vector<int> adj[]){  // tc : o(n) + o(n+2m)
    int cnt = 0 ;
    int vis[n+1] = {0} ; // sc : o(n)

    for(int i=1 ;i<=n ;i++){
        if(!vis[i]){
            dfstraversal(adj ,i, vis) ;  // sc : o(n)
            cnt++ ;
        }
    }

    return cnt ;
}

int main(){
    int n = 8; // number of vertices
    int m = 7 ; // number of edges

    vector<int> adj[n + 1]; // adjacency list from 1 to n

    // predefined input edges
    vector<pair<int, int>> edges = {
        {1, 2},
        {1, 3},
        {2, 4},
        {3, 4}, 
        {5, 6},  
        {5, 7},
        {6, 7},   
    };

    // populate adjacency list
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }   
    
    int ans = numprovince(n, adj) ;
    cout << ans << endl;

    return 0 ;
}