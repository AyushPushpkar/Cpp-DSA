#include<bits/stdc++.h>
using namespace std ;

/*
*          
*    1——→2——→3——→4
*        ↑   ↓   ↓ ↘             
*        8   7——→5←——6
*       ↙↖
*      9——→0
*
*/       

//? indegree - no of incoming edges to a node

// tc : o(V) + o(E)
vector<int> safestates(int n , vector<int> adj[] ){
    vector<int> ans ;

    vector<int> adjrev[n] ;
        vector<int> indegree(n,0) ;

    for(int i=0 ;i<n ;i++){
        for(auto it : adj[i]){
            adjrev[it].push_back(i) ;
            indegree[i] ++ ;
        }
    }

    queue<int> q ;

    for(int i = 0 ; i< n ;i++){
        if(indegree[i] ==0) q.push(i) ;
    }

    while(!q.empty()){
        int node = q.front() ;
        q.pop() ;
        ans.push_back(node) ;

        // node in topo sort so remove it from indegree
        for(auto it : adjrev[node]){
            indegree[it]-- ;
            if(indegree[it] == 0) q.push(it) ;
        }
    }

    return ans ;
}

int main(){
    int n = 10; // number of vertices

    vector<int> adj[n]; // adjacency list from 0 to n-1

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
        {9, 0},
        {0, 8},   
    };

    // populate adjacency list
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
    }   
    
    vector<int> ans = safestates(n , adj ) ;

    for(auto it : ans){
        cout << it << " " ;
    }

    return 0 ;
}