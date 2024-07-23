#include<bits/stdc++.h>
using namespace std ;

//floor value 

int binary(int n){
    int ans = 1 ;
    int low =1 , high =n;

    while(low<= high){
        int mid = (low+high)/2 ;
        if(mid*mid <= n){
            ans = mid ;
            low = mid+1 ;
        }
        else{
            high = mid-1 ;
        }
    }
    //return ans ;
    return high ;
}

int linear(int n){
    int ans = 1 ;

    for(int i=1 ; i<= n ;i++){
        if(i*i <= n){
            ans = i ;
            continue;
        }
        else break;
    }
    return ans ;
}

int main(){

    int n ;
    cin >> n;

    cout << linear(n) << endl;

    //till certain place ans possible
    //after that not posible -> binary
    
    //min max
    //ans range -> binary

    cout << binary(n) << endl ;
}