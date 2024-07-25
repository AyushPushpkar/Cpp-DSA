#include<bits/stdc++.h>
using namespace std ;

//min no of days to make m bouquets
//if not possible -1

int maxE(int a[] ,int n){
    int maxi = INT_MIN ;

    for(int i=0 ; i<n ;i++){
        maxi = max(maxi , a[i]) ;
    }
    return maxi ;
}

int minE(int a[] ,int n){
    int mini = INT_MAX ;

    for(int i=0 ; i<n ;i++){
        mini = min(mini , a[i]) ;
    }
    return mini ;
}

bool possible(int a[] ,int n , int m ,int k ,int i){
    int cnt = 0;
    int noB = 0 ;
    for(int j=0 ;j<n ;j++){
        if(a[j] <= i){
            cnt += 1 ;
        }
        else{
            noB += cnt/k ;
            if( noB >= m) return true ;
                cnt = 0;
            }
        }
    noB += cnt/k ;
    if( noB >= m) return true ;
    return false ;
}

int binary(int a[] ,int n ,int m , int k){
    if(n < m*k) return -1 ;
    int low  = minE(a,n) , high = maxE(a,n) ;

    while(low <= high){
        int mid = (low + high)/2 ;
        if(possible(a,n,m,k,mid) == 1){
            high = mid -1;
        }
        else{
            low = mid +1 ;
        }
    }
    return low  ;
}

int bouquets(int a[] ,int n , int m ,int k){
    if(n < m*k) return -1 ;
    int minDay = minE(a,n);
    int maxDay = maxE(a,n) ;

    for(int i = minDay  ;i <= maxDay ; i++){   // tc : o((max-min+1)*n)
        if(possible(a,n,m,k,i) == 1) return i ;
    }

    return -1 ;
}

int main(){
    int n =8 ;  // no of flowers 
    //bloom day
    int a[] = {7,7,7,7,13,11,12,7} ;

    int m =2 ; // no of bouquets
    int k = 3 ; //adjacent flowers required

    //range 7->13
    cout << bouquets(a,n,m,k) << endl ;

    cout << binary(a,n,m,k) << endl ;

}