#include<bits/stdc++.h>
using namespace std ;

/*
*          
*    1——→2——→3——→4
*        ↑   ↓   ↓ ↘             
*        8   7——→5←——6
*       ↗↖
*      9——→0
*
*/       

// tc : o(V) + o(E)
vector<int> courceSchedule(int n , vector<pair<int,int>> prerequisites){

    vector<int> adj[n]; 

    for (auto edge : prerequisites) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
    }  

    vector<int> ans ;

    vector<int> indegree(n,0) ;
    queue<int> q ;

    for(int i = 0 ; i< n ;i++){
        for(auto it : adj[i]){
            indegree[it] ++ ;
        }
    }

    for(int i = 0 ; i< n ;i++){
        if(indegree[i] ==0) q.push(i) ;
    }

    while(!q.empty()){
        int node = q.front() ;
        q.pop() ;
        ans.push_back(node) ; 

        // node in topo sort so remove it from indegree
        for(auto it : adj[node]){
            indegree[it]-- ;
            if(indegree[it] == 0) q.push(it) ;
        }
    }

    if(ans.size() == n)return ans ;
    return {} ; 
}

int main(){
    int n = 10; // number of vertices

    vector<pair<int, int>> edges = {
        {1, 2},   // u before v
        {2, 3}, 
        {3, 4},
        {3, 7},
        {4, 5}, 
        {4, 6},
        {6, 5}, 
        {7, 5},
        {8, 2},
        {9, 8},
        {9, 0},
        {0, 8},   
    }; 
    
    vector<int> ans = courceSchedule(n , edges ) ;

    for(auto it : ans){
        cout << it << " " ;
    }

    return 0 ;
}