#include<bits/stdc++.h>
using namespace std;

/*
Problem:
Rod cutting - maximize profit cutting rod into pieces with given prices.
*/

// TC: O(n²) | SC: O(n)

int rodCuttingOptimal(vector<int >&pieces , int  rodlen ) {

    int n = pieces.size() ;
    if(n==0)return 0 ; 

    vector<int>prev (rodlen+1,0) , curr (rodlen+1,0) ;

    prev[0] = 0 ;

    for (int w = 1; w <= rodlen; w++)  prev[w] = w * pieces[0];

    for(int idx = 1 ; idx <n ; idx++){
        for(int w = 0 ; w <= rodlen ; w++ ){
            int notpick = prev[w] ;
            int pick = 0 ;
            if(idx+1 <= w) pick = pieces[idx]+ prev[w - (idx+1)] ;

            prev[w] = max(notpick , pick) ; 
        }
    }
    
    return prev[rodlen] ; 
    
}

int rodCutting(vector<int >&pieces , int  rodlen) {

    int n = pieces.size() ;
    if(n==0)return 0 ; 

    vector<int>prev (rodlen+1,0) , curr (rodlen+1,0) ;

    prev[0] = curr[0] = 0 ;

    for (int w = 1; w <= rodlen; w++)  prev[w] = w * pieces[0];

    for(int idx = 1 ; idx <n ; idx++){
        for(int w =0 ; w <= rodlen ; w++ ){
            int notpick = prev[w] ;
            int pick = 0 ;
            if(idx+1 <= w) pick = pieces[idx]+ curr[w - (idx+1)] ;

            curr[w] = max(notpick , pick) ; 
        }
        prev = curr ;
    }
    
    return prev[rodlen] ;
    
}

int rodCuttingTab(vector<int >&pieces , int  rodlen ) {

    int n = pieces.size() ;
    if(n==0)return 0 ; 

    vector<vector<int>>dp (n , vector<int>(rodlen+1,0)) ;

    for(int i = 0 ; i<n ; i++) dp[i][0] = 0 ;

    for (int w = 1; w <= rodlen; w++)  dp[0][w] = w * pieces[0];

    for(int idx = 1 ; idx <n ; idx++){
        for(int w =1 ; w <= rodlen ; w++ ){
            int notpick = dp[idx-1][w] ;
            int pick = 0 ;
            if(idx+1 <= w) pick = pieces[idx]+ dp[idx][w - (idx+1)] ;

            dp[idx][w] = max(notpick , pick) ; 
        }
    }
    
    return dp[n-1][rodlen] ;
}

int rodCuttingHelper(vector<int>&pieces , int idx ,int rodlen  , vector<vector<int>>&dp) {

    if(rodlen == 0) return false ;

    if (idx == 0) {
        if (rodlen >= 1 ) return rodlen * pieces[0];
        else return 0;
    }

    if(dp[idx][rodlen] != -1 ) return dp[idx][rodlen] ;

    int notpick = rodCuttingHelper(pieces , idx-1 , rodlen , dp ) ;
    int pick = 0 ;
    if(idx+1 <= rodlen) pick = pieces[idx] + rodCuttingHelper(pieces ,  idx , rodlen- (idx+1) , dp ) ;

    return dp[idx][rodlen] = max(notpick , pick) ; 
}


int rodCuttingMemo(vector<int >&pieces , int  rodlen){

    int n = pieces.size() ;
    if(n==0)return 0 ; 

    vector<vector<int>>dp (n , vector<int>(rodlen+1,-1)) ;

    return rodCuttingHelper(pieces , n-1 , rodlen ,dp ) ;

}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    vector<int>pieces = {2 ,5 ,7,8,9} ;
    cout << rodCuttingMemo(pieces , 5) << endl ;
    cout << rodCuttingTab(pieces , 5) << endl ;
    cout << rodCutting(pieces , 5) << endl ;
    cout << rodCuttingOptimal(pieces , 5) << endl ;
}