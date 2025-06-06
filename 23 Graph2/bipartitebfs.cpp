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

bool bfsgraph(vector<int> &vis , int n , vector<int> adj[] , int startnode){

    vis[startnode] = 0 ;
    cout << startnode << " 0" << endl ; 
    
    queue<int> q ;  // sc :  o(n)
    q.push(startnode) ;

    while(!q.empty()){  // tc : o(n) + o(2m)
        int node = q.front();
        q.pop() ;

        for(auto it : adj[node]){
            if(vis[it] == -1){
                vis[it] = !vis[node] ;
                cout << it << " " << vis[it] << endl ;
                q.push(it) ;
            }
            else if(vis[it] == vis[node]){
                return false ; 
                cout << "false" << it << endl;
            }
        }
    }

    return true ;

}

bool bipartitebfs(int n , vector<int> adj[] , int startnode){

    vector<int> vis(n + 1, -1); // All elements initialized to -1 ; // sc : o(n)

    for(int i = 1 ; i<= n ;i++){
        if(vis[i] == -1){
            if(bfsgraph(vis , n ,  adj , i)== false) return false ;
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
    
    bool ans = bipartitebfs(n , adj ,4 ) ;

    cout << ans << endl ; 

    return 0 ;
}