#include<bits/stdc++.h>
using namespace std ;

int searchRotated(int a[] ,int n,int target){
    int low = 0 , high = n-1 ;

    while(low <= high){
        int mid = (low+high)/2 ;
        if(a[mid] == target) return mid ;
        //left sorted
        if ( a[low] <= a[mid]){
            if(target <= a[mid] && target >= a[low]){
                high = mid-1 ;
            }
            else{
                low = mid+1 ;
            }
        }
        else{
            if(target >= a[mid] && target <= a[high]){
                low = mid+1 ;
            }
            else{
                high = mid -1 ;
            }
        }
    }
    return -1 ;
    
}

int main(){
    int n =9 ;
    int a[n] = {7,8,9,1,2,3,4,5,6} ;

    int x ;
    cin >> x ;

    cout << searchRotated(a,n,x) << endl;
}