#include<bits/stdc++.h>
using namespace std ;

/*
Problem:
Find maximum profit from single buy-sell transaction.
*/

// TC: O(n) | SC: O(1)
int stocks(int a[] , int n){
    int mini = a[0] ;
    int profit = 0;
    for(int i=1;i<n ;i++){      // tc o(n)
        int cost = a[i] - mini ;
        profit = max(cost , profit) ;
        mini = min(mini ,a[i]);
    }
    return profit ;
}

int main(){
    int n = 8 ;
    int a[] = {7,3,5,8,2,6,1,4} ;

    cout << stocks(a,n) << endl ;
}