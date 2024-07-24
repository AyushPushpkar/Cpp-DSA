#include<bits/stdc++.h>
using namespace std ;

//floor value 

int func(int mid , int n , int target){
    //return 0 if <m
    //return 1 if == m
    //return 2 if > m
    long long ans = 1 ;

    for(int i =1 ;i<=n;i++){           // o(logn)
        ans = ans*mid ;
        if (ans > target) return 2 ;  // for edge cases
    }
    if(ans == target) return 1;
    return 0 ;
}

int binary(int n , int target){
    int ans = -1 ;
    int low =1 , high = target;

    while(low<= high){
        int mid = (low+high)/2 ;
        int midN = func(mid , n , target) ;
        if(midN == 1) return mid ;
        else if(midN == 0){
            low = mid+1 ;
        }
        else{
            high = mid-1 ;
        }
    }
    return ans ;
}

int powi(int i , int n){
    int ans = 1 ;

    while(n>0){           // o(logn)
        if(n%2 == 1){
            ans = ans *i;
            n= n-1 ;
        }
        else{
            i = i*i ;
            n = n/2 ;
        }
    }
    // i^n ;
    return ans ;
}

int linear(int n , int target){
    int ans = -1 ;

    for(int i=1 ; i<= target ;i++){  //tc : o(m* logn)
        int mul = powi(i , n) ;
        if(mul == target){
            ans = i ;
            break;
        }
        else if(mul > target){
            break;
        }
    }
    return ans ;
}

int main(){

    int n , m;
    cin >> n >> m;

    cout << linear(n , m) << endl;

    cout << binary(n , m) << endl ;
}