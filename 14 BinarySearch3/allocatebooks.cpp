#include<bits/stdc++.h>
using namespace std ;

//each student at least one book
//each book to only one student
//allocation in contiguous manner 
// (max no of pages assigned to students) is min

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

int studentCnt(int a[] ,int n ,int mid){
    int stcnt = 1 ;
    int sum= 0 ;
    for(int j=0 ;j<n ;j++){
        sum += a[j] ;
        if(sum > mid){
            stcnt ++ ;
            sum = a[j] ;
        }
    }
    return stcnt ;
}

int binary(int a[] ,int n ,int students){
    if(students > n) return -1 ;

    int low = *max_element(a,a+n) ;
    int high = accumulate(a,a+n,0) ; // 0 is starting value to add other values

    while(low <= high){             // o(log(sum-max+1)*n)
        int mid = (low+high)/2 ;
        int stcnt = studentCnt(a,n,mid) ;
        if(stcnt > students){
            low = mid+1 ;
        }
        else{
            high = mid-1 ;
        }
    }
    return low ;
}

int linear(int a[] ,int n ,int students){
    if(students > n) return -1 ;

    int minHold = maxE(a,n) ;
    int maxHold = sumE(a,n) ;
    cout << minHold << " " << maxHold << endl ;

    for(int i= minHold ;i<=maxHold ;i++){  // o((sum-max+1)*n)
        int stcnt = studentCnt(a,n,i) ;
        if(stcnt == students )return i ;
    }
    return -1 ;
}

int main(){
    int n = 5 ;  // books
    int a[] = {25,46,28,49,24} ;  // no of pages

    int students = 4 ;

    cout << linear(a,n ,students) << endl ;

    cout << binary(a,n ,students) << endl ;
}