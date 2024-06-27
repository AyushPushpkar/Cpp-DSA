#include<bits/stdc++.h>
using namespace std;

void hcf(int n , int m){
    stack<int>st;
    int i,l;
    l=min(n,m);
    for(i=1; i<=l; i++){
        if((n%i==0)&&(m%i==0)){
            cout << i << " " ;
            st.push(i);
        }
    }cout << endl << "hcf " << st.top();
}

void hcf2(int n , int m){
    int i,l ,gcd =1;
    l=min(n,m); // o(min(n,m))
    for(i=1; i<=l; i++){
        if((n%i==0)&&(m%i==0)){
            gcd =i ;
        }
    }cout << endl << "hcf# " << gcd << " ";

    cout << "lcm " << (n*m)/gcd ;
}

void hcf3(int n , int m){
    int i,l ,gcd =1;
    l=min(n,m); // o(min(n,m))
    for(i=l; i>=1; i--){
        if((n%i==0)&&(m%i==0)){
            gcd =i ; 
            break; 
        }   
    }
    cout << endl << "hcf& " << gcd << endl;
}

void hcf4(int n , int m){
    while((n!=0)&&(m!=0)){
        if(n>m)n=n%m;
        else m=m%n;
    }// o(log (min(n,m)))
    if(n==0)cout << m;
    if(m==0)cout << n;   
}

int main(){
    int n,m;
    cin >> n >> m ;
    hcf(n,m);
    hcf2(n,m);
    hcf3(n,m);
    hcf4(n,m);
    return 0;
}

