#include<bits/stdc++.h>
using namespace std ;

/*   
*
*      4       3       2
*    0 ——     ———— 3 ————
*    |   \ /     6        \
*  4 |    2 —————————————— 5
*    |   / \              /
*    1 ——     ———— 4 ————    
*      2       1       3
*
*/        

//! no negative weight
//? tc : o(ElogV)

vector<int> dijkstrapath(int n , vector<vector<pair<int, int>>> adj  ,int src , int dst){

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_min ; 

    vector<int> dis (n , INT_MAX) ; 
    dis[src] = 0;

    pq_min.push({0, src}) ;

    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    while(!pq_min.empty()){  // tc : o(n) + o(2m)
        int node = pq_min.top().second  ;
        int dist = pq_min.top().first ;
        pq_min.pop() ;

        for(auto it : adj[node]){
            int adjnode = it.first ; 
            int wt = it.second ;
            if(dist + wt < dis[adjnode]){
                dis[adjnode] = wt + dist;
                pq_min.push({dis[adjnode] , adjnode}) ;
                parent[adjnode] = node ;
            }
        }
    }

    vector<int> path ;

    if(dis[dst]== INT_MAX) return {-1} ;
    int node = dst ;

    while(parent[node] != node){
        path.push_back(node) ;
        node = parent[node] ;
    } 
    path.push_back(src) ; 
    reverse(path.begin() , path.end()) ; 
        
    return path ;
}

int main(){
    int n = 6; // number of vertices

        vector<vector<pair<int, int>>> adj(n);

    // edges as ((u, v), weight)
    vector<tuple<int, int, int>> edges = {
        {0, 1, 4},
        {0, 2, 4},
        {1, 2, 2},
        {2, 3, 3},
        {2, 4, 1},
        {2, 5, 6},
        {3, 5, 2},
        {4, 5, 3}
    };

    // populate adjacency list
    for (auto edge : edges) {
        int u = get<0>(edge);
        int v = get<1>(edge);
        int wt = get<2>(edge);
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }  


    int dst = 5 ;
    
    vector<int> ans = dijkstrapath(n , adj , 0 ,dst ) ;

    for(auto it : ans){
        if(it == dst) cout << it ;
            else cout << it <<  " -> " ; 
    }

    return 0 ;
}