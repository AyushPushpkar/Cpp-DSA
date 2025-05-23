#include<bits/stdc++.h>
using namespace std ;

/*
*       1
*      / \
*     2   3
*      \ / \
*       4   5
*        \ / \
*         6---7
*              \
*               8
*/

void dfstraversal( vector<int> adj[] , int startnode , int vis[] , vector<int> &dfs){

    vis[startnode] = 1 ;

    dfs.push_back(startnode) ;   // tc : o(n) + o(2m) 

    for(auto it : adj[startnode]){  // degree
        if(!vis[it]){
            dfstraversal(adj,it , vis ,dfs) ;
        }
    }

}

vector<int> dfsgraph(int n , vector<int> adj[] , int startnode){
    vector<int> dfs ;  // sc  : o(n)

    int vis[n+1] = {0} ; // sc : o(n)

    dfstraversal(adj, startnode , vis ,dfs) ; //sc : o(n)

    return dfs ;
}

int main(){
    int n = 8; // number of vertices
    int m = 10 ; // number of edges

    vector<int> adj[n + 1]; // adjacency list from 1 to n

    // predefined input edges
    vector<pair<int, int>> edges = {
        {1, 2},
        {1, 3},
        {2, 4},
        {3, 4}, 
        {3, 5},
        {4, 6},
        {5, 6},  
        {5, 7},
        {6, 7},   
        {7,8}
    };

    // populate adjacency list
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }   
    
    vector<int> ans = dfsgraph(n , adj ,1 ) ;

    for(int it : ans){
        cout << it << " " ;
    }cout << endl ;

    return 0 ;
}