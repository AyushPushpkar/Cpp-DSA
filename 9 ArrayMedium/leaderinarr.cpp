#include<bits/stdc++.h>
using namespace std ;
//everything on right is smaller

void optimal(int a[] , int n){
    vector<int>v ;      // o(n)    to return
    int maxi = INT_MIN ;
    
    for(int i=n-1;i>=0;i--){        // o(n)
        if(a[i]>maxi){
            v.push_back(a[i]);
            maxi = max(maxi ,a[i]);
        }
    }

    reverse(v.begin(),v.end());    // o(n)
    for(auto it:v){
        cout << it << " " ;
    }
    cout << endl ;
}

void brute(int a[] , int n){
    vector<int>v ;
    
    for(int i=0;i<n;i++){        //tc : o(n^2)
        bool leader = true ;
        for(int j=i+1;j<n;j++){
            if(a[j]>a[i]){
                leader = false ;
                break;
            }
        }
        if(leader){
            v.push_back(a[i]);   //sc : o(n)
        } 
    }
    for(auto it:v){
        cout << it << " " ;
    }
    cout << endl ;
}

int main(){
    int n =6;
    int a[n] = {10,22,12,3,0,6} ;

    brute(a,n) ;
    optimal(a,n);
}