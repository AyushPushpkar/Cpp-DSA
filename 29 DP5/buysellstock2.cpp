#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
        
    int n = prices.size() ; 
    vector<int> ahead(2,0) , curr(2,0) ;
        
    for(int i = n-1 ; i>= 0 ; i--){
        curr[1] = max(-prices[i] + ahead[0] ,  ahead[1]); 
        curr[0] = max(prices[i] +  ahead[1] ,  ahead[0]);

        ahead = curr ; 
    }

    return curr[1] ; 
}

int maxProfitTab(vector<int>& prices) {
        
    int n = prices.size() ; 
    vector<vector<int>> dp(n+1 , vector<int>(2,-1)) ; 

    dp[n][0] = dp[n][1] = 0 ; 
        
    for(int i = n-1 ; i>= 0 ; i--){
        dp[i][1] = max(-prices[i] + dp[i+1][0] , dp[i+1][1]); 
        dp[i][0] = max(prices[i] + dp[i+1][1] , dp[i+1][0]);
    }

    return dp[0][1] ; 
}

int stock(vector<int>& prices , bool buy , int i , vector<vector<int>> &memo){
    if(i == prices.size() - 1){
    if(buy) return 0 ; 
        else return memo[i][buy] = prices[i] ; 
    }

    if(memo[i][buy] != -1) return memo[i][buy] ; 

    int profit = 0 ; 
    if(buy){
        profit = max(-prices[i] + stock(prices , !buy , i+1 ,memo ) ,
                    stock(prices , buy , i+1  , memo)); 
    }else{
        profit = max(prices[i] + stock(prices , !buy , i+1 , memo) ,
                    stock(prices , buy , i+1  , memo)) ;
    }

    return memo[i][buy] = profit ; 
}

int maxProfitMemo(vector<int>& prices) {
        
    int n = prices.size() ; 
    vector<vector<int>> memo(n , vector<int>(2,-1)) ; 
    return  stock(prices , true , 0 , memo) ; ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int>a = {7,3,5,8,2,6,1,4} ;

    cout << maxProfitMemo(a) << endl ;
    cout << maxProfitTab(a) << endl ;

    return 0;
}