#include<bits/stdc++.h>
using namespace std ;

// cnt = index of min 

int cntRotated(int a[] ,int n){
    int mini = INT_MAX ;
    int low = 0 , high = n-1 ;
    int index = -1 ;

    while(low <= high){          // tc : o(logn)
        int mid = (low+high)/2 ;
        
        if(a[low] <= a[high]){
            if(a[low] < mini){
                mini = a[low] ;
                index = low ;
            }
            break;
        }

        //left sorted
        if ( a[low] <= a[mid]){
            if(a[low] < mini){
                mini = a[low] ;
                index= low ;
            }
            low = mid+1;
        }// right sorted 
        else{
            if(a[mid] < mini){
                mini = a[mid] ;
                index= mid ;
            }
            high  = mid-1 ;
        }
    }
    return index ;
    
}

int main(){
    int n = 5 ;
    int a[n] = {3,4,5,1,2} ;

    cout << cntRotated(a,n) << endl ;
}