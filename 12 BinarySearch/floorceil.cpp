#include<bits/stdc++.h>
using namespace std ;

//floor = largest no in arr <= x
//ceil = smallest no. in arr >= x

int floor(int a[] ,int n ,int target){
    int ans = -1 ;   //tc  :  o(log2(n))

    int low = 0 , high = n-1 ;

    while(low <= high){
        int mid = (low+high)/2 ;
        if(a[mid] <= target){
            ans = mid ;
            low = mid+1 ;
        } 
        else {
            high = mid - 1 ;
        }
    }
    return ans  ;
}

int lbound(int a[] ,int n ,int target){  // ceil
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
    int n = 7;
    int a[n] = {1,2,4,7,9,11,20} ;

    int x ;
    cin >> x ;
    auto lb =  lbound(a,n,x) ;
    cout << "ceil = " << a[lb] << endl;

    auto f =  floor(a,n,x) ;
    cout << "floor = " << a[f] << endl;
}