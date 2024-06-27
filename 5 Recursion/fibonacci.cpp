#include<bits/stdc++.h>
using namespace std;

int fibo(int n){
    if(n<=1)return n;
    else return fibo(n-2)+fibo(n-1); //o(2^n)
}

void fibo2(int n){
    int a[n];
    a[0]=0;
    a[1]=1;
    for(int i=2;i<=n;i++){
        a[i]=a[i-1]+a[i-2];
    }
    for(int i=0;i<=n;i++){
        cout << a[i] << " ";
    }
}

void fibo3(int n){
    vector<int>v(n); //for index assign size
    v[0]=0;
    v[1]=1;
    for(int i=2;i<n;i++){
        v[i]=v[i-1]+v[i-2];
    }
    for(int i=0;i<n;i++){
        cout << v[i] << " ";
    }
}

int main(){
    int n ;
    cin >> n ;
    fibo(n);
    cout << fibo(n) << endl ;
    fibo2(n);
}