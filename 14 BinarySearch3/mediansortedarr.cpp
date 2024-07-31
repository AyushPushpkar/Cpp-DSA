#include<bits/stdc++.h>
using namespace std ;

double optimal(int arr1[],int n ,int arr2[] , int m){
    // for arr1 is always smaller
    if(n>m) return optimal(arr2,m,arr1,n) ;
    int low = 0 , high = n ;      // tc : o(min(logn , logm))
    int left = (n+m+1)/2 ;
    int total = n+m ;

    while(low <=high){
        int mid1 = (low+high) >> 1 ; // right shift
        int mid2 = left - mid1 ;
        int l1 = INT_MIN , l2 = INT_MIN ;
        int r1 = INT_MAX , r2 = INT_MAX ;
        if(mid1 < n) r1 = arr1[mid1] ;
        if(mid2 < m) r2 = arr2[mid2] ;
        if(mid1 - 1 >= 0) l1 = arr1[mid1 -1] ;
        if(mid2 -1 >= 0) l2 = arr2[mid2-1] ;

        if(l1 <= r2 && l2 <= r1){
            if(total%2==1) return max(l1,l2) ;
            return (double)(max(l1,l2) + min(r1,r2))/2.0 ;
        }
        else if(l1 > r2) high = mid1-1 ;
        else low = mid1+1 ;
    }
    return -1 ;
}

double median(int arr1[],int n ,int arr2[] , int m){
    int left = 0;
    int right = 0 ;
    int total = n+m ;
    int ind2 = total/2 ;
    int ind1 = ind2 -1 ;
    int cnt =0 ;
    int el1 = -1 , el2 = -1 ;
    while((left<n)&&(right<m)){         // o(total)   TLE
        if(arr1[left]<=arr2[right]) {
            if(cnt == ind1) el1 = arr1[left] ;
            if(cnt == ind2) el2 = arr1[left] ;
            cnt++ ;
            left++ ;
        }
        else {
            if(cnt == ind1) el1 = arr2[right] ;
            if(cnt == ind2) el2 = arr2[right] ;
            cnt++ ;
            right++ ;
        }
    }
    while(left<n){
        if(cnt == ind1) el1 = arr1[left] ;
        if(cnt == ind2) el2 = arr1[left] ;
        cnt++ ;
        left++ ;
    }
    while(right<m){
        if(cnt == ind1) el1 = arr2[right] ;
        if(cnt == ind2) el2 = arr2[right] ;
        cnt++ ;
        right++ ;
    }
    
    
    if(total%2==1){
        return el2 ;
    }
    else{
        return (double)((double)(el1+el2))/2.0 ;
    }
}

double merge(int arr1[],int n ,int arr2[] , int m){
    vector<int>v;   // sc : o(total)
    int left = 0;
    int right = 0 ;
    while((left<n)&&(right<m)){          //o (total)
        if(arr1[left]<=arr2[right]) v.push_back(arr1[left ++]);
        else v.push_back(arr2[right++]) ;
    }
    while(left<n){
        v.push_back(arr1[left ++]);
    }
    while(right<m){
        v.push_back(arr2[right++]) ;
    }
    
    int total = n+m ;
    if(total%2==1){
        return v[total/2] ;
    }
    else{
        double avg = ((double)v[total/2] + (double)v[total/2 -1])/2.0 ;
        return avg ;
    }
}

int main(){
    int n = 6 ;
    int arr1[] = {1,3,4,7,10,12} ;

    int m= 4 ;
    int arr2[] = {2,3,6,15} ; 

    cout << merge(arr1,n,arr2,m) << endl ;

    cout << median(arr1,n,arr2,m) << endl ;

    cout << optimal(arr1,n,arr2,m) << endl ;
}
