#include<bits/stdc++.h>
using namespace std ;

//identify  sorted half

int minRotated(int a[] ,int n){
    int mini = INT_MAX ;
    int low = 0 , high = n-1 ;

    while(low <= high){          // tc : o(logn)
        int mid = (low+high)/2 ;
        
        if(a[low] == a[mid] && a[mid] == a[high]){
            low++;
            high-- ;
            continue;
        }

        if(a[low] <= a[high]){
            mini = min(mini , a[low]);
            break;
        }

        //left sorted
        if ( a[low] <= a[mid]){
            mini = min(mini, a[low]) ;
            low = mid+1;
        }// right sorted 
        else{
            mini = min(mini  ,a[mid]) ;
            high  = mid-1 ;
        }
    }
    return mini ;
    
}

int main(){
    int n =9 ;
    int a[n] = {3,3,1,2,3,3,3,3,3} ;

    int m = 7 ;
    int arr[m] ={7,7,7,7,1,6,7} ;

    int arr2[] = {1,2,3,4,1,1,1,1,1} ;

    cout << minRotated(a,n) << endl;

    cout << minRotated(arr,m) << endl;

    cout<< minRotated(arr2 , n) << endl ;
}