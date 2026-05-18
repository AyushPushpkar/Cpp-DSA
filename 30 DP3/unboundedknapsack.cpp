#include<bits/stdc++.h>
using namespace std;

int ubknapsackOptimal(vector<pair<int ,int>>&items , int  bag_wt ) {

    int n = items.size() ;
    if(n==0)return 0 ; 

    vector<int>prev (bag_wt+1,0) ;

    prev[0] = 0 ;

    for (int w = items[0].first; w <= bag_wt; w++)  prev[w] = ((int)(w/items[0].first)) * items[0].second;

    for(int idx = 1 ; idx <n ; idx++){
        for(int w = 0 ; w <= bag_wt ; w++ ){
            int notpick = prev[w] ;
            int pick = 0 ;
            if(items[idx].first <= w) pick = items[idx].second + prev[w-items[idx].first] ;

            prev[w] = max(notpick , pick) ; 
        }
    }
    
    return prev[bag_wt] ; 
    
}

int ubknapsack(vector<pair<int ,int>>&items , int  bag_wt ) {

    int n = items.size() ;
    if(n==0)return 0 ; 

    vector<int>prev (bag_wt+1,0) , curr (bag_wt+1,0) ;

    prev[0] = curr[0] = 0 ;

    for (int w = items[0].first; w <= bag_wt; w++)  prev[w] = (w/items[0].first) * items[0].second;

    for(int idx = 1 ; idx <n ; idx++){
        for(int w =1 ; w <= bag_wt ; w++ ){
            int notpick = prev[w] ;
            int pick = 0 ;
            if(items[idx].first <= w) pick = items[idx].second + curr[w-items[idx].first] ;

            curr[w] = max(notpick , pick) ; 
        }
        prev = curr ; 
    }
    
    return prev[bag_wt] ; 
    
}

int ubknapsackTab(vector<pair<int ,int>>&items , int  bag_wt ) {

    int n = items.size() ;
    if(n==0)return 0 ; 

    vector<vector<int>>dp (n , vector<int>(bag_wt+1,0)) ;

    for(int i = 0 ; i<n ; i++) dp[i][0] = 0 ;

    for (int w = items[0].first; w <= bag_wt; w++)  dp[0][w] = (w/items[0].first) * items[0].second;

    for(int idx = 1 ; idx <n ; idx++){
        for(int w =1 ; w <= bag_wt ; w++ ){
            int notpick = dp[idx-1][w] ;
            int pick = 0 ;
            if(items[idx].first <= w) pick = items[idx].second + dp[idx][w-items[idx].first] ;

            dp[idx][w] = max(notpick , pick) ; 
        }
    }
    
    return dp[n-1][bag_wt] ;
}

int ubknapsackHelper(vector<pair<int,int>>&items , int idx ,int bag_wt  , vector<vector<int>>&dp) {

    if(bag_wt == 0) return false ;

    if (idx == 0) {
        if (bag_wt >= items[0].first ) return  (bag_wt/items[0].first) * items[0].second;
        else return 0;
    }

    if(dp[idx][bag_wt] != -1 ) return dp[idx][bag_wt] ;

    int notpick = ubknapsackHelper(items , idx-1 , bag_wt , dp ) ;
    int pick = 0 ;
    if(items[idx].first <= bag_wt) pick = items[idx].second + ubknapsackHelper(items ,  idx , bag_wt-items[idx].first , dp ) ;

    return dp[idx][bag_wt] = max(notpick , pick) ; 
}


int ubknapsackMemo(vector<pair<int ,int>>&items , int  bag_wt){

    int n = items.size() ;
    if(n==0)return 0 ; 

    vector<vector<int>>dp (n , vector<int>(bag_wt+1,-1)) ;

    return ubknapsackHelper(items , n-1 , bag_wt ,dp ) ;

}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    vector<pair<int , int>>nums = {{2 , 5} , {4,11},{6,13}} ;
    cout << ubknapsackMemo(nums , 10) << endl ;
    cout << ubknapsackTab(nums , 10) << endl ;
    cout << ubknapsack(nums , 10) << endl ;
    cout << ubknapsackOptimal(nums , 10) << endl ;
}