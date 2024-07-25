#include<bits/stdc++.h>
using namespace std ;

// min integer k (bananas /hr she eats)
//such that koko eats all within h hours

int maxE(int a[] ,int n){
    int maxi = INT_MIN ;

    for(int i=0 ; i<n ;i++){
        maxi = max(maxi , a[i]) ;
    }
    return maxi ;
}

int totalHr(int a[] ,int n ,int hourly){
    int totalH = 0 ;

    for(int i=0 ;i<n ;i++){
        totalH += ceil((double)a[i] / (double)hourly) ;
    }

    return totalH ;
}

int binary(int a[] ,int n ,int h){
    int low =1 , high = maxE(a,n);

    while(low<= high){
        int mid = (low+high)/2 ;
        int totalH = totalHr(a,n,mid) ;
        if(totalH <= h){
            high = mid-1 ;
        }
        else{
            low = mid +1 ;
        }
    }
    //return ans ;
    return low ;
}

int main(){
    int n = 4; 
    //piles of bananas
    int a[] = {3,4,7,11} ;

    int h = 8 ;

    // range of k -> [1 - maxEl]

    cout << "k -> " << binary(a,n,h) << endl ;
}