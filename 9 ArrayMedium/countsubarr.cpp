#include<bits/stdc++.h>
using namespace std ;

int optimal(int a[],int n,int s){
    map<int,int>mp ;
    int sum =0;
    int cnt = 0 ;
    mp[0] = 1;

    for(int i=0;i<n;i++){
        sum += a[i] ;
        int rem =sum -s ;
        cnt += mp[rem];
        mp[sum] += 1;
        
    }
    return cnt ;
}

int brute(int a[], int n, int s) {
    int cnt =0 ;

    for (int i = 0; i < n; i++) {    //tc ~ o(n^2)
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            if(sum == s)
            cnt++ ;
        }
    }
    return cnt;
}

int main(){
    int n=10;
    int a[n] ={1,2,3,-3,1,1,1,4,2,-3} ;

    int s = 3;

    cout << brute(a,n,s) << endl ;

    cout << optimal(a,n,s) << endl ;
}