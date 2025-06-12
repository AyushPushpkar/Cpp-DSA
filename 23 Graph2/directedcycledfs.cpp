#include<bits/stdc++.h>
using namespace std ;

/*
*          
*    1——→2——→3——→4
*        ↑   ↓   ↓ ↘             
*        8   7——→5←——6
*      ↙  ↖
*     9———→10
*/                    

bool dfstraversal( vector<int> adj[] , int startnode , int vis[] , int path[] ){

    vis[startnode] = 1 ; 
    path[startnode] = 1 ;

    for(auto it : adj[startnode]){ 
        if(!vis[it]){
            if(dfstraversal(adj,it , vis , path)) return true ;
        }
        else if(path[it]){
            return true ;
        }
    }

    path[startnode] = 0 ;

    return false ;

}

// tc : o(n) + o(E)
bool isCycle(int n , vector<int> adj[] ){

    int vis[n+1] = {0} ; // sc : o(n)
    int path[n+1] = {0} ; // sc : o(n)

    for(int i = 1 ; i<= n ;i++){
        if(!vis[i]){
            if(dfstraversal(adj , i , vis , path )== true) return true ;   // sc : o(n)
        }
    }

    return false ;
}

int main(){
    int n = 10; // number of vertices

    vector<int> adj[n + 1]; // adjacency list from 1 to n

    // predefined input edges
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
        {9, 10},
        {10, 8},   
    };

    // populate adjacency list
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
    }   
    
    bool ans = isCycle(n , adj ) ;

    cout << ans << endl ;

    return 0 ;
}