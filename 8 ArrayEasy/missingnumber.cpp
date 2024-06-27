#include<bits/stdc++.h>
using namespace std ;

void missingnumberoptimal2(int a[] ,int n){

    int XOR = 0 ,XOR2 = 0 ;         
    for(int i=0 ; i<n-1 ;i++){     // tc  o(n)
        XOR = XOR^(i+1);         
        XOR2 = XOR2^a[i];
    }
    int num = XOR^XOR2^n ;
    cout << num << endl ;
}

void missingnumberoptimal1(int a[] ,int n){

    int sum= n*(n+1)/2 ;
    
    int add = 0 ;               // sc o(1)
    for(int i=0 ; i<n-1 ;i++){    // tc  o(n)
        add+= a[i] ;
    }
    cout << sum-add << endl ;
}

void missingnumberbetter(int a[] ,int n){

    int hash[n+1] = {0} ;     // tc o(n)
                              // sc o(n)
    for(int i=0;i<n-1;i++){
        hash[a[i]]+=1;
    }

    for(int i=1 ; i<=n ;i++){
        if(hash[i]==0)
        cout << i << endl ;
    }
}

int missingnumberbrute(int a[] , int n){

    for(int i=1 ;i<=n;i++){         // tc o(n*n)
        int flag = 0;              // sc o(1)
        for(int j=0;j<n-1;j++){
            if(a[j]==i){
                flag = 1;
                break ;
            }
        }
        if(flag == 0)
        return i ;
    }
}

int main(){
    int n= 5;
    int a[n-1] = {1,2,3,5} ;

    cout << missingnumberbrute(a,n) << endl;

    missingnumberbetter(a,n) ;

    missingnumberoptimal1(a,n) ;

    missingnumberoptimal2(a,n) ;
}