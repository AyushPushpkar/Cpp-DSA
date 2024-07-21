#include<bits/stdc++.h>
using namespace std ;

// (even, odd ) - el in right half
// (odd , even ) - el in left half

int binary(int a[] ,int n){
    if(n==1) return a[0] ;
    if(a[0] != a[1]) return a[0] ;
    if(a[n-1] != a[n-2]) return a[n-1] ;

    int low = 1 , high = n-2 ;

    while(low <= high){
        int mid = (low+ high) /2 ;
        if(a[mid] != a[mid -1] && a[mid] != a[mid +1]){
            return a[mid] ;
        }
        //el in right half 
        if((a[mid] == a[mid-1] && mid%2 == 1) || (mid%2 == 0 && a[mid] == a[mid+1])){
            low = mid +1 ;
        }
        //el in left half
        else {
            high = mid -1 ;
        }
    }
    return -1 ;
}

int brutesearch(int a[] ,int n){

    for(int i=0 ;i<n ;i++){    // o(n)
        if( i== 0){
            if(a[i] != a[i+1]){
                return a[i] ;
            }
        }
        else if( i== n-1){
            if(a[i] != a[i-1]){
                return a[i] ;
            }
        }
        else{
            if(a[i] != a[i-1] && a[i] != a[i+1]){
                return a[i] ;
            }
        }
    }
    return -1 ;
}

int main(){
    int n= 9 ;
    int a[n] ={1,1,2,2,3,3,4,5,5,6,6} ;

    cout << brutesearch(a,n) << endl ;

    cout << binary(a,n) << endl ;
}