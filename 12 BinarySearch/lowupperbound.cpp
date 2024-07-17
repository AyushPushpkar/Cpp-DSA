#include<bits/stdc++.h>
using namespace std ;

//lower bound : smallest index a[index] >= x 
//upper bound : smallest index a[index] > x 

int ubound(int a[] ,int n ,int target){
    int ans = n ;   //tc  :  o(log2(n))

    int low = 0 , high = n-1 ;

    while(low <= high){
        int mid = (low+high)/2 ;
        if(a[mid] > target){
            ans = mid ;
            high = mid - 1 ;
        } 
        else {
            low = mid+1 ;
        }
    }
    return ans  ;
}

int lbound(int a[] ,int n ,int target){
    int ans = n ;   //tc  :  o(log2(n))

    int low = 0 , high = n-1 ;

    while(low <= high){
        int mid = (low+high)/2 ;
        if(a[mid] >= target){
            ans = mid ;
            high = mid - 1 ;
        } 
        else {
            low = mid+1 ;
        }
    }
    return ans  ;
}

int main(){
    int n =10 ;
    int a[n] = {1,2,3,3,7,8,9,9,9,11} ;

    int x ;
    cin >> x ;

    cout << lbound(a,n,x) << endl ;

    int* lb = lower_bound(a,a+n , x) ;
    cout << *lb << " at index " << (lb-a) <<endl ;

    cout << ubound(a,n,x) << endl ;

    int* ub = upper_bound(a,a+n , x) ;
    cout << *ub << " at index " << (ub-a) <<endl ;
}