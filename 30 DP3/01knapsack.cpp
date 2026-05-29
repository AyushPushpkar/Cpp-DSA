#include<bits/stdc++.h>
using namespace std;

/*
Problem:
0/1 Knapsack - maximize value with capacity constraint (each item used 0 or 1 time).
*/

// TC: O(n × W) | SC: O(n × W) where W = capacity

/*
Problem:
You are given a list of `items` (weight, value) and a knapsack capacity `bag_wt`.

Rules:
- You can either pick an item or not (0/1 method).
- Total weight of picked items must not exceed `bag_wt`.

Task:
Return the maximum total value you can pack in the knapsack.
*/

int z1knapsackOptimal(vector<pair<int ,int>>&items , int  bag_wt ) {

    int n = items.size() ;
    if(n==0)return 0 ; 

    vector<int>prev (bag_wt+1,0) ;

    prev[0] = 0 ;

    for (int w = items[0].first; w <= bag_wt; w++)  prev[w] = items[0].second;

    for(int idx = 1 ; idx <n ; idx++){
        for(int w =bag_wt ; w >= 0 ; w-- ){
            int notpick = prev[w] ;
            int pick = 0 ;
            if(items[idx].first <= w) pick = items[idx].second + prev[w-items[idx].first] ;

            prev[w] = max(notpick , pick) ; 
        }
    }
    
    return prev[bag_wt] ; 
    
}

int z1knapsack(vector<pair<int ,int>>&items , int  bag_wt ) {

    int n = items.size() ;
    if(n==0)return 0 ; 

    vector<int>prev (bag_wt+1,0) , curr (bag_wt+1,0) ;

    prev[0] = curr[0] = 0 ;

    for (int w = items[0].first; w <= bag_wt; w++)  prev[w] = items[0].second;

    for(int idx = 1 ; idx <n ; idx++){
        for(int w =1 ; w <= bag_wt ; w++ ){
            int notpick = prev[w] ;
            int pick = 0 ;
            if(items[idx].first <= w) pick = items[idx].second + prev[w-items[idx].first] ;

            curr[w] = max(notpick , pick) ; 
        }
        prev = curr ; 
    }
    
    return prev[bag_wt] ; 
    
}

int z1knapsackTab(vector<pair<int ,int>>&items , int  bag_wt ) {

    int n = items.size() ;
    if(n==0)return 0 ; 

    vector<vector<int>>dp (n , vector<int>(bag_wt+1,0)) ;

    for(int i = 0 ; i<n ; i++) dp[i][0] = 0 ;

    for (int w = items[0].first; w <= bag_wt; w++)  dp[0][w] = items[0].second;

    for(int idx = 1 ; idx <n ; idx++){
        for(int w =1 ; w <= bag_wt ; w++ ){
            int notpick = dp[idx-1][w] ;
            int pick = 0 ;
            if(items[idx].first <= w) pick = items[idx].second + dp[idx-1][w-items[idx].first] ;

            dp[idx][w] = max(notpick , pick) ; 
        }
    }
    
    return dp[n-1][bag_wt] ;
}

int z1knapsackHelper(vector<pair<int,int>>&items , int idx ,int bag_wt  , vector<vector<int>>&dp) {

    if(bag_wt == 0) return false ;

    if (idx == 0) {
        if (bag_wt >= items[0].first) return  items[0].second;
        else return 0;
    }

    if(dp[idx][bag_wt] != -1 ) return dp[idx][bag_wt] ;

    int notpick = z1knapsackHelper(items , idx-1 , bag_wt , dp ) ;
    int pick = 0 ;
    if(items[idx].first <= bag_wt) pick = items[idx].second + z1knapsackHelper(items ,  idx-1 , bag_wt-items[idx].first , dp ) ;

    return dp[idx][bag_wt] = max(notpick , pick) ; 
}


int z1knapsackMemo(vector<pair<int ,int>>&items , int  bag_wt){

    int n = items.size() ;
    if(n==0)return 0 ; 

    vector<vector<int>>dp (n , vector<int>(bag_wt+1,-1)) ;

    return z1knapsackHelper(items , n-1 , bag_wt ,dp ) ;

}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    vector<pair<int , int>>nums = {{2 , 30} , {3,30},{2,40} , {5,60}} ;
    cout << z1knapsackMemo(nums , 6) << endl ;
    cout << z1knapsackTab(nums , 6) << endl ;
    cout << z1knapsack(nums , 6) << endl ;
    cout << z1knapsackOptimal(nums , 6) << endl ;
}