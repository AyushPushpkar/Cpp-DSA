#include<bits/stdc++.h>
using namespace std ;

//smallest divisor given a threshold

int maxE(int a[] ,int n){
    int maxi = INT_MIN ;

    for(int i=0 ; i<n ;i++){
        maxi = max(maxi , a[i]) ;
    }
    return maxi ;
}

int binary(int a[] ,int n , int threshold){
    if(n > threshold) return -1 ;
    int high = maxE(a,n) , low = 1 ;

    while(low <= high){     // tc :  o(log(maxi) * n)
        int mid = (low+high)/2 ;  
        int sum = 0 ;
        for(int j = 0 ; j<n ;j++){
            sum += ceil((double)a[j]/(double)mid) ;
        }
        if(sum <= threshold){
            high = mid-1 ;
        }
        else{
            low = mid+1 ;
        }
    }

    return low ;
}

int divisors(int a[] ,int n , int threshold){
    if(n > threshold)return -1 ; 
    int maxi = maxE(a,n) ;

    for(int i = 1;i <= maxi ; i++){    // tc : o(maxi * n)
        int sum = 0 ;
        for(int j = 0 ; j<n ;j++){
            sum += ceil((double)a[j]/(double)i) ;
        }
        if(sum <= threshold) return i ;
    }

    return -1 ;
}

int main(){
    int n= 4 ;
    int a[] = {1,2,5,9} ;

    int m = 6 ;

    //range [1 -> max el]
    cout << divisors(a,n,m) << endl ;

    cout << binary(a,n,m) << endl ;
}