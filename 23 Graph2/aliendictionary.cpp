#include<bits/stdc++.h>
using namespace std ;

/*
*          
*      b——→a——→c
*       ↘↗
*        d
*
*/       

//? N - numbers of words , k - starting alphabets of standard dictionary

vector<int> topologicalSorting(int n , vector<int> adj[] ){
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

    return ans ;
}

string aliendict(int N , int k , string dict[]){

    vector<int> adj[k]; 

    for(int i =0 ; i<N-1 ; i++){
        string s1 = dict[i] ;
        string s2 = dict[i+1] ; 
        int len = min(s1.size() , s2.size()) ; 

        for(int ptr = 0 ;ptr<len ;ptr++){
            if(s1[ptr] != s2[ptr]){
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a') ;
                break;
            }
        }
    }

    vector<int> topo = topologicalSorting(k , adj) ; 

    string ans = "" ;
    for(auto it : topo){
        ans+= char(it +'a') ; 
    }

    return ans ; 

}

int main(){
    int N = 5 , k = 5 ;
    
    string dict[] = { "baa" , "abcd" , "abca" , "cab" , "cad"} ;


    string ans = aliendict(N , k , dict) ; 
    for(auto it : ans){
        cout << it << " " ;
    }

    return 0 ;
}