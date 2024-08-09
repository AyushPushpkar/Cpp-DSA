#include<bits/stdc++.h>
using namespace std ;

// (min dis b/w cows) is max
bool canWePlace(int a[] ,int n ,int cows ,int dist){
    int cntcows = 1 ,last = a[0] ;

    for(int i=1 ;i<n ;i++){
        if(a[i] - last >= dist){
            cntcows++ ;
            last = a[i] ;
        }
        if(cntcows >= cows) return true ;
    }
    return false ;
}

int binary(int a[],int n ,int cows){
    int low = 1 ,high =a[n-1] - a[0] ;

    while(low<=high){    //tc : o(log(max-min)*n)
        int mid = (low+high)/2 ;
        if(canWePlace(a,n,cows,mid) == 1){
            low = mid+1;
        }
        else{
            high = mid-1 ;
        }
    }
    return high ;
}

int linear(int a[],int n ,int cows){
    int min = a[0] ,max =a[n-1] ;

    for(int i=1 ;i< (max-min) ;i++){    //tc : o((max-min)*n)
        if(canWePlace(a,n,cows,i) == 1){
            continue;
        }
        else{
            return i-1 ;
        }
    }
    return -1 ;
}

int main(){
    int n = 6 ;
    int a[] = {0,3,4,7,10,9} ;  // coordinates of stalls

    int cows = 4 ;

    sort(a,a+n) ;

    cout << linear(a,n,cows) << endl ;

    cout << binary(a,n,cows) << endl ;

}