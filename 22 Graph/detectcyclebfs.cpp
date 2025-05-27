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

bool bfsgraph(int vis[] , int n , vector<int> adj[] , int startnode){


    vis[startnode] = 1 ;

    queue<pair<int,int>> q ;  // sc :  o(n)
    q.push({startnode,-1}) ;

    while(!q.empty()){  // tc : o(n) + o(2m)
        int currnode = q.front().first;
        int parent = q.front().second ;
        q.pop() ;

        for(auto adjnode : adj[currnode]){
            if(!vis[adjnode]){
                vis[adjnode] = 1 ;
                q.push({adjnode,currnode}) ;
            }
            else if(parent != adjnode){
                return true ;
            }
        }
    }

}

bool isCycle(int n , vector<int> adj[] , int startnode){

    int vis[n+1] = {0} ; // sc : o(n)

    for(int i = 1 ; i<= n ;i++){
        if(!vis[i]){
            if(bfsgraph(vis , n ,  adj , i)== true) return true ;
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