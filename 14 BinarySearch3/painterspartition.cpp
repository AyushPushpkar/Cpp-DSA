#include<bits/stdc++.h>
using namespace std ;

// painter"s partiotion / split arr - largest sum
//each painter at least one job
//consecutive
//(max time) is min

//minimized largest sum of the split.

int Painters(int a[] ,int n , int mid){
    int painter = 1 ;
    int sum = 0 ;
    for(int j =0 ;j<n ;j++){
        sum += a[j] ;
        if(sum > mid){
            painter ++ ;
            sum = a[j] ;
        }
    }
    return painter ;
}

int binary(int a[] ,int n ,int painters){
    if(painters > n) return -1 ;

    int low = *max_element(a,a+n) ;
    int high = accumulate(a,a+n,0) ;

    while(low <= high){  // o(n)
        int mid = (low+high) / 2 ;
        int painter = Painters(a,n,mid) ;
        if(painter <= painters){
            high = mid-1 ;
        }
        else{
            low = mid - 1 ;
        }
    }
    return low;
}

int linear(int a[] ,int n ,int painters){
    if(painters > n) return -1 ;

    int minArea = *max_element(a,a+n) ;
    int maxArea = accumulate(a,a+n,0) ;

    for(int i= minArea ;i<=maxArea ;i++){  // o(n)
        int painter = Painters(a,n,i) ;
        if(painter == painters) return i ;
    }
    return -1;
}

int main(){
    int n =4;
    int a[] = {10,20,30,40} ;  //units of area

    //in order to paint 10 unit of area , 10 unit of time is req

    int k = 3  ;  // no of painters

    cout << linear(a,n,k) << endl ;

    cout << binary(a,n,k) << endl ;
    
}