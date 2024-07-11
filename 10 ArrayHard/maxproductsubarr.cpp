#include<bits/stdc++.h>
using namespace std ;

int optmal(int a[] , int n){
    int prefix =1 ,suffix =1 ;
    int product = INT_MIN ;

    for(int i=0;i<n ;i++){               // tc : o(n)
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1 ;     
        prefix *= a[i] ;
        suffix *= a[n-1-i] ;
        product = max(product , max(prefix ,suffix)) ;
    }

    return product ;
}

int brute(int a[] ,int n){
    int product = INT_MIN;

    for(int i=0;i<n ;i++){      // tc : o(n^2)
        int mul = 1 ;
        for(int j=i;j<n;j++){
            mul *= a[j] ;
            product = max(mul ,product) ;
        }
    }

    return product ;
}

int main(){
    int n =4 ;
    int a[n] ={2,3,-2,4};

    cout << brute(a,n) << endl; 

    cout << optmal(a,n) << endl; 
}