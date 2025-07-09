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

vector<int> dijkstra(int n , vector<vector<pair<int, int>>> adj  ,int src){

    set<pair<int, int>> set ; 

    vector<int> dis (n , INT_MAX) ; 
    dis[src] = 0;

    set.insert({0, src}) ;

    while (!set.empty()) {
        auto it = *(set.begin());
        int node = it.second;
        int dist = it.first;
        set.erase(it);

        for (auto &neighbor : adj[node]) {
            int adjNode = neighbor.first;
            int weight = neighbor.second;

            if (dist + weight < dis[adjNode]) {
                // romve the larger dist
                if (dis[adjNode] != INT_MAX) {
                    set.erase({dis[adjNode], adjNode});
                }
                dis[adjNode] = dist + weight;
                set.insert({dis[adjNode], adjNode});
            }
        }
    }

    vector<int> ans(n , -1) ;

    for(int i =0 ; i< n ; i++){
        if(dis[i] != INT_MAX) ans[i] = dis[i] ;
    }
        
    return ans ;
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
    
    vector<int> ans = dijkstra(n , adj , 0  ) ;

    for (int i=0 ; i<n ; i++){
        cout << i << " " << ans[i]  << endl  ; 
    }

    return 0 ;
}