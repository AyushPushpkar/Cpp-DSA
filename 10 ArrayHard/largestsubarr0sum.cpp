#include<bits/stdc++.h>
using namespace std ;

int better(int a[] , int n){
    int maxlen = INT_MIN ;
    int sum = 0 ;
    map<int,int>mp ;

    for(int i=0 ;i<n ;i++){
        sum += a[i] ;
        if (sum == 0) {
            maxlen = max(maxlen, i + 1); 
        }
 
        if(mp.find(sum) != mp.end()){
            int len = i - mp[sum] ; 
            maxlen = max(len , maxlen) ;
        }else{
            mp[sum] = i ;
        }
    }
    return maxlen ;
}

int brute(int a[] , int n){
    int maxlen = INT_MIN ;

    for(int i=0 ;i<n ;i++){
        int sum = 0 ;
        for(int j=i ;j<n ;j++){
            sum += a[j] ;
            if(sum == 0){
                int len = j-i+1 ;
                maxlen = max(len , maxlen) ;
            }
        }
    }
    return maxlen ;
}

int main(){
    int n = 8 ;
    int a[n] = {15,-2,2 , -8 ,1 ,7,10,23} ;

    cout << brute(a,n) << endl ;

    cout << better(a,n) << endl ;
}