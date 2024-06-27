#include<bits/stdc++.h>
using namespace std ;

int ones( int a[] , int n){
    int maxi = 0 ;
    int cnt =  0 ;

    for(int i =0;i<n ;i++){
        if(a[i] == 1){
            cnt += 1 ;
            maxi = max(maxi ,cnt) ;
        }
        else{
            cnt = 0 ;
        }
    }
    return maxi ;
}

int main(){
    int n = 10; 
    int a[n] = {1,0,0,1,1,1,0,1,1,0} ;

    cout << ones(a,n) << endl ;
}