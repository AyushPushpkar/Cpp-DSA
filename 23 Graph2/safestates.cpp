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

bool dfstraversal( vector<int> adj[] , int startnode , int vis[] ,int check[] ){

    vis[startnode] =  2; 

    for(auto it : adj[startnode]){ 
        if(vis[it] == 0){
            if(dfstraversal(adj,it , vis , check )) return true ; // cycle is detected
        }
        else if(vis[it] == 2){
            return true ; // cycle is detected
        }
    }

    vis[startnode] = 1 ;
    check[startnode] = 1 ;  // no cycle is detected

    return false ;

}

// tc : o(n) + o(E)
vector<int> safeNode(int n , vector<int> adj[] , int startnode){

    vector<int> ans ;
    int check[n+1] = {0} ;  // sc : o(n)

    int vis[n+1] = {0} ; // sc : o(n)

    for(int i = 1 ; i<= n ;i++){
        if(!vis[i]){
            dfstraversal(adj , i , vis  , check) ;   // sc : o(n)
        }
    }
    for(int i=1 ;i<=n ;i++){
        if(check[i] ==1) ans.push_back(i) ;
    }

    return ans ;
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
    
    vector<int> ans = safeNode(n , adj , 1 ) ;

    for(auto it : ans){
        cout << it << endl ;
    }

    return 0 ;
}