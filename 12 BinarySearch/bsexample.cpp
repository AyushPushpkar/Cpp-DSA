#include<bits/stdc++.h>
using namespace std ;

//search space is sorted

int iterative(int a[] ,int n,int target){
    int low = 0 , high = n-1 ;

    while(low <= high){
        int mid = (low+high)/2 ;
        if(a[mid] == target) return mid ;
        else if ( a[mid] < target){
            low = mid+1 ;
        }
        else{
            high = mid-1 ;
        }
    }
    return -1 ;
    
}

int recursive(int a[] ,int low , int high ,int target){
    if(low > high) return -1 ;      // tc : o(logn)
    int mid = (low+high)/2 ;
    if(a[mid] == target) return mid ;
    else if ( a[mid] < target){
        return recursive(a,mid+1 ,high , target) ;
    }
    else{
        return recursive(a,low,mid-1 ,target) ;
    }  
}

int main(){
    int n = 8 ;
    int a[] = {3,4,6,7,9,12,16 ,17} ;
    int target = 16 ;

    cout << iterative(a,n , target) << endl;
    cout << recursive(a,0 ,n-1 , target) ;

    //if INT_MAX
    // mid = low + (high - low)/2
}