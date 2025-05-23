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

vector<int> bfsgraph(int n , vector<int> adj[] , int startnode){

    vector<int> bfs ;  // sc  : o(n)

    int vis[n+1] = {0} ; // sc : o(n)
    vis[startnode] = 1 ;

    queue<int> q ;  // sc :  o(n)
    q.push(startnode) ;

    while(!q.empty()){  // tc : o(n) + o(2m)
        int node = q.front();
        q.pop() ;
        bfs.push_back(node) ;

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1 ;
                q.push(it) ;
            }
        }
    }

    return bfs ;
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
        adj[v].push_back(u); // undirected graph
    }   
    
    vector<int> ans = bfsgraph(n , adj ,4 ) ;

    for(int it : ans){
        cout << it << " " ;
    }cout << endl ;

    return 0 ;
}