#include<bits/stdc++.h>
using namespace std ;

int multiPeak(int a[] ,int n){
    if(n== 1) return a[0] ;
    if(a[0] > a[1]) return a[0] ;
    if(a[n-1] > a[n-2]) return a[n-1] ;
    int low = 1 , high = n-2;;

    while(low<= high){
        int mid = (low + high)/2 ;
        if(a[mid] > a[mid+1] && a[mid] > a[mid-1]){
            return a[mid] ;
        }
        //peak at right
        else if((a[mid -1 ] <a[mid]) ){  
            low = mid +1 ;
        }
        //peak at left
        else {
            high = mid -1 ;
        }
    }
    return -1 ;
}

int onePeak(int a[] ,int n){
    if(n== 1) return a[0] ;
    if(a[0] > a[1]) return a[0] ;
    if(a[n-1] > a[n-2]) return a[n-1] ;
    int low = 1 , high = n-2;;

    while(low<= high){
        int mid = (low + high)/2 ;
        if(a[mid] > a[mid+1] && a[mid] > a[mid-1]){
            return a[mid] ;
        }
        //peak at right
        else if((a[mid -1 ] <a[mid]) ){  // inc curve
            low = mid +1 ;
        }
        //peak at left
        else if(a[mid] > a[mid+1]){                       // dec curve
            high = mid -1 ;
        }
    }
    return -1 ;
}

void brute(int a[] ,int n){
    vector<int>peak ;       // tc : o(n)

    for(int i =0 ;i<n ;i++){
        if((i==0 || a[i] > a[i-1]) && (i==n-1 || a[i] > a[i+1])){
            peak.push_back(a[i]) ;
        }
    }

    for(auto it : peak){
        cout << it << " " ;
    }
    cout << endl ;
}

int main(){
    int n = 10 ;
    int a[n] = {1,2,3,4,5,6,7,8,5,1} ;

    brute(a,n) ;

    cout << onePeak(a,n) << endl ;

    int arr[n] = {1,8,3,4,5,6,7,8,9,1} ;

    cout << multiPeak(arr,n) ;
}