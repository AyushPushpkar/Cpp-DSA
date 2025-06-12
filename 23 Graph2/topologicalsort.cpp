#include<bits/stdc++.h>
using namespace std ;

/*
*          
*    1——→2——→3——→4
*        ↑   ↓   ↓ ↘             
*        8   7——→5←——6
*      ↗  ↖
*     9———→10
*
*/       

//? linear ordering of vertices such that if there is an edge between u & v, u appears before v.
//? directed acyclic graph

void dfstraversal( vector<int> adj[] , int startnode , int vis[] , stack<int> &st ){

    vis[startnode] = 1 ; 

    for(auto it : adj[startnode]){ 
        if(!vis[it]){
            dfstraversal(adj,it , vis , st) ;
        }
    }

    st.push(startnode) ;

}

// tc : o(V) + o(E)
vector<int> topologicalSorting(int n , vector<int> adj[] , int startnode){

    int vis[n+1] = {0} ; // sc : o(n)
    vector<int> ans;
    stack<int> st ; // sc : o(n)

    for(int i = 1 ; i<= n ;i++){
        if(!vis[i]){
            dfstraversal(adj , i , vis ,st ) ;   // sc : o(n)
        }
    }

    while(!st.empty()){
        int node = st.top() ;
        st.pop() ;
        ans.push_back(node) ;
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
        {9, 8},
        {9, 10},
        {10, 8},   
    };

    // populate adjacency list
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
    }   
    
    vector<int> ans = topologicalSorting(n , adj , 1 ) ;

    for(auto it : ans){
        cout << it << " " ;
    }

    return 0 ;
}