#include<bits/stdc++.h>
using namespace std ;

/*
*       1
*      / \
*     2   3
*      \   
*       4   5---8
*          / \
*         6---7
*
                           
*/

bool dfstraversal( vector<int> adj[] , int startnode , int vis[] , int parent){

    vis[startnode] = 1 ; 

    for(auto it : adj[startnode]){ 
        if(!vis[it]){
            if(dfstraversal(adj,it , vis , startnode)) return true ;
        }
        else if(parent != it){
            return true ;
        }
    }

    return false ;

}

// tc : o(n+2m) + o(n)
bool isCycle(int n , vector<int> adj[] , int startnode){

    int vis[n+1] = {0} ; // sc : o(n)

    // for provinces
    for(int i = 1 ; i<= n ;i++){
        if(!vis[i]){
            if(dfstraversal(adj , i , vis  , -1)== true) return true ;   // sc : o(n)
        }
    }

    return false ;
}

int main(){
    int n = 8; // number of vertices
    int m = 8 ; // number of edges

    vector<int> adj[n + 1]; // adjacency list from 1 to n

    // predefined input edges
    vector<pair<int, int>> edges = {
        {1, 2},
        {1, 3},
        {2, 4}, 
        // {3, 5},
        // {4, 6},  
        {5, 6}, 
        {5, 7},
        {5, 8},
        {6, 7},   
    };

    // populate adjacency list
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }   
    
    bool ans = isCycle(n , adj , 1 ) ;

    cout << ans << endl ;

    return 0 ;
}