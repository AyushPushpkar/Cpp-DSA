#include<bits/stdc++.h>
using namespace std ;

//if present return index
//if not present where should be inserted

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