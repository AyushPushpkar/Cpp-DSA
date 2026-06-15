#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
        
    int n = prices.size() ; 
    vector<int> front2(2,0) , front1(2,0) , curr(2,0) ; 
        
    for(int i = n-1 ; i>= 0 ; i--){
        curr[1] = max(-prices[i] + front1[0] , front1[1]); 
        curr[0] = max(prices[i] + front2[1] , front1[0]);

        front2 = front1 ; 
        front1 = curr ; 
    }

    return curr[1] ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int>a = {7,3,5,8,2,6,1,4} ;

    cout << maxProfit(a) << endl ;

    return 0;
}