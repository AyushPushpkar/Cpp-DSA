#include<bits/stdc++.h>
using namespace std ;

/*
*          3
*       1 ——→ 2 
*    2↗     ↗  ↘6        
*    0   2 ⁄     3
*    1↘  ⁄     ↗1         
*       4 ——→ 5
*          4
*/        

void dfstraversal( vector<vector<pair<int, int>>> adj , int startnode , int vis[] , stack<int> &st ){

    vis[startnode] = 1 ; 

    for(auto it : adj[startnode]){ 
        if(!vis[it.first]){
            dfstraversal(adj,it.first , vis , st) ;
        }
    }

    st.push(startnode) ;

}

vector<int> shortestpathDAC(int n , vector<vector<pair<int, int>>> adj  ,int src){

    int vis[n] = {0} ; // sc : o(n)
    stack<int> st ; // sc : o(n)

    for(int i = 0 ; i< n ;i++){
        if(!vis[i]){
            dfstraversal(adj , i , vis ,st ) ;   // sc : o(n)
        }
    }

    vector<int> dist (n , INT_MAX) ; 
    dist[src] = 0; 

    while(!st.empty()){
        int node = st.top() ;
        st.pop() ; 
        
        for ( auto it : adj[node]){
            int adjnode = it.first ; 
            int wt = it.second ; 

            dist[adjnode] = min( dist[adjnode] , wt + dist[node]) ; 
        }
    } 

    return dist ;
}

int main(){
    int n = 6; // number of vertices

    // define adjacency list for nodes 0 to n
    vector<vector<pair<int, int>>> adj(n);

    // edges as ((u, v), weight)
    vector<tuple<int, int, int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {1, 2, 3},
        {2, 3, 6},
        {4, 2, 2},
        {4, 5, 4},
        {5, 3, 1}
    };

    // populate adjacency list
    for (auto edge : edges) {
        int u = get<0>(edge);
        int v = get<1>(edge);
        int wt = get<2>(edge);
        adj[u].push_back({v, wt});
    }  

    // print the adjacency list
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << ": ";
        for (auto pair : adj[i]) {
            cout << "(" << pair.first << ", wt=" << pair.second << ") ";
        }
        cout << endl;
    }cout << endl;
    
    vector<int> ans = shortestpathDAC(n , adj , 0  ) ;

    for (int i=0 ; i<n ; i++){
        cout << i << " " << ans[i]  << endl  ; 
    }

    return 0 ;
}