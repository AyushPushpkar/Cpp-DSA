#include<bits/stdc++.h>
using namespace std ;

//least capacity to ship packages in D days

int maxE(int a[] ,int n){
    int maxi = INT_MIN ;

    for(int i=0 ; i<n ;i++){
        maxi = max(maxi , a[i]) ;
    }
    return maxi ;
}

int sumE(int a[] ,int n){
    int sum = 0 ;

    for(int i=0 ; i<n ;i++){
        sum += a[i] ;
    }
    return sum ;
}

int dayCnt(int a[] ,int n ,int mid){
    int sum = 0 ;
    int daycnt = 1 ;
    for(int j = 0 ; j<n ;j++){
        sum += a[j] ;
        if(sum > mid){
            daycnt += 1 ;
            sum = a[j] ;
        }
    }
    return daycnt ;
}

int binary(int a[] ,int n , int days){
    int high = sumE(a,n)  , low = maxE(a,n) ;

    while(low <= high){     // tc :  o(log(sum - max +1) * n)
        int mid = (low+high)/2 ;  
        int daycnt = dayCnt(a,n,mid) ;
        if(daycnt <= days){
            high = mid-1 ;
        }
        else{
            low = mid+1 ;
        }
    }

    return low ;
}

int ship(int a[] ,int n , int days){
    int mini = maxE(a,n) ;
    int maxi = sumE(a,n) ;

    for(int i = mini;i <= maxi ; i++){    // tc : o((sum -max +1) * n)
        int daycnt = dayCnt(a,n,i) ;
        if(daycnt <= days) return i ;
    }

    return -1 ;
}

int main(){
    int n = 10 ;
    int a[] ={1,2,3,4,5,6,7,8,9,10} ;

    int days = 5 ;

    //range of capacity [maxel -> sum of all]

    cout << ship(a,n,days) << endl ;

    cout << binary(a,n,days) << endl ;
}