#include<bits/stdc++.h>
using namespace std ;

//duplicates allowed

bool searchRotated(int a[] ,int n,int target){
    int low = 0 , high = n-1 ;
                                  //tc : worst ~ o(n/2)
    while(low <= high){          // tc : avg o(logn)
        int mid = (low+high)/2 ;
        if(a[mid] == target) return true ;
        // trim down
        if(a[low] == a[mid] && a[mid] == a[high]){
            low++;
            high-- ;
            continue;
        }
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
    return false ;
    
}

int main(){
    int n =9 ;
    int a[n] = {6,6,7,1,2,3,4,5,6} ;

    int x ;
    cin >> x ;

    cout << searchRotated(a,n,x) << endl;
}