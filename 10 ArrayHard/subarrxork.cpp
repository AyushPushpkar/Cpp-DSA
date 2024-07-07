#include<bits/stdc++.h>
using namespace std ;

int optimal(int a[],int n,int k){
    map<int,int>mp ;     //sc o(n)
    int XOR =0;
    int cnt = 0 ;
    mp[0] = 1;

    for(int i=0;i<n;i++){    //tc  o(nlogn)
        XOR = XOR^a[i] ;
        int x = XOR^k ;
        cnt += mp[x];
        mp[XOR] += 1;
        
    }
    return cnt ;
}

int brute(int a[] ,int n ,int k){
    int cnt =0 ;

    for(int i=0;i<n;i++){     // o(n^2)
        int XOR =0 ;
        for(int j=i;j<n;j++){
            XOR = XOR^a[j] ;
            if(XOR == k){
                cnt++ ;
            }
        }
    }
    return cnt ;
}

int main(){
    int n=5 ;
    int a[n] ={4,2,2,6,4} ;

    int k =6 ;

    cout << brute(a,n,k) << endl ;

    cout << optimal(a,n,k) << endl ;
}