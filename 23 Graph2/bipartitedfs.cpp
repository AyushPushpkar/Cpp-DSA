#include<bits/stdc++.h>
using namespace std ;

/*
*          3
*         / \
*    1---2   4---7---8
*        |   |
*        6---5
*       
*/

bool dfstraversal( vector<int> adj[] , int startnode , vector<int> &vis , int col){

    vis[startnode] = col ;
    cout << startnode << " " << vis[startnode] << endl;

    for(auto it : adj[startnode]){ 
        if(vis[it] == -1){
            if(dfstraversal(adj,it , vis , !col)== false) return false ;
        }
        else if(vis[it] == vis[startnode]){
            return false ;
        }
    }

    return true ;

}

bool bipartitedfs(int n , vector<int> adj[] , int startnode){

    vector<int> vis(n + 1, -1); // sc : o(n)

    for(int i = 1 ; i<= n ;i++){
        if(vis[i] == -1){
            if(dfstraversal(adj , i ,  vis , 0)== false) return false ;
        }
    }

    return true ;
}

int main(){
    int n = 8; // number of vertices
    int m = 8 ; // number of edges

    vector<int> adj[n + 1]; // adjacency list from 1 to n

    // predefined input edges
    vector<pair<int, int>> edges = {
        {1, 2},
        {2, 3},
        {2, 6},
        {3, 4}, 
        {4, 5},
        {4, 7},
        {5, 6},     
        {7,8}
    };

    // populate adjacency list
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }   
    
    bool ans = bipartitedfs(n , adj ,4 ) ;

    cout << ans << endl ; 

    return 0 ;
}