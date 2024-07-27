#include<bits/stdc++.h>
using namespace std ;

int binary(int a[] ,int n , int k){
    if(k > (a[n-1] - n)) return -1 ;
    int high = n-1  , low = 0 ;

    while(low <= high){     // tc :  o(logn)
        int mid = (low+high)/2 ;  
        int missing = a[mid] - (mid+1) ;
        if(missing < k){
            low = mid +1 ;
        }
        else{
            high = mid-1 ;
        }
        //ans b/w high -> low
    }
    //  more = k - (a[high] - (high+1)) ;
    //  ans = a[high] + more ;
    //ans = k + (high+1)
    int ans = k+low ;  

    return ans ;
}

int brute(int a[] ,int n ,int k){
    if(k > (a[n-1] - n)) return -1 ;

    for(int i=0 ;i<n ;i++){   // tc : o(n)
        if(a[i] <= k){
            k++ ;
        }
        else break;
    }
    return k ;
}

int main(){
    int n =5 ;
    int a[] = {2,3,4,7,11} ;

    int k=5 ;

    cout << brute(a,n ,k) <<  endl ;

    cout << binary(a,n ,k) <<  endl ;

}