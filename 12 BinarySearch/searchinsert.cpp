#include<bits/stdc++.h>
using namespace std ;

/*
Problem:
Search for target in sorted array; if found return index, else return insertion position.
*/

// TC: O(log n) | SC: O(1)
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
    int n = 4;
    int a[n] = {1,2,4,7} ;

    int x ;
    cin >> x ;
    cout << lbound(a,n,x) << endl ;
}