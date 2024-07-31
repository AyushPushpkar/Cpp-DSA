#include<bits/stdc++.h>
using namespace std ;

double kthEl(int arr1[],int n ,int arr2[] , int m , int k){
    // for arr1 is always smaller
    if(n>m) return kthEl(arr2,m,arr1,n , k) ;
    int low = max(0 , k-m) , high = min(k,n) ;      // tc : o(min(logn , logm))
    int left = k ;
    int total = n+m ;

    while(low <=high){
        int mid1 = (low+high) >> 1 ; // right shift
        int mid2 = left - mid1 ;
        int l1 = INT_MIN , l2 = INT_MIN ;
        int r1 = INT_MAX , r2 = INT_MAX ;
        if(mid1 < n) r1 = arr1[mid1] ;
        if(mid2 < m) r2 = arr2[mid2] ;
        if(mid1 - 1 >= 0) l1 = arr1[mid1 -1] ;
        if(mid2 -1 >= 0) l2 = arr2[mid2-1] ;

        if(l1 <= r2 && l2 <= r1){
            return max(l1,l2) ;
        }
        else if(l1 > r2) high = mid1-1 ;
        else low = mid1+1 ;
    }
    return -1 ;
}

int main(){
    int n = 6 ;
    int arr1[] = {1,3,4,7,10,12} ;

    int m= 4 ;
    int arr2[] = {2,3,6,15} ; 

    int k= 4 ;

    cout << kthEl(arr1,n,arr2,m ,k) << endl ;
}