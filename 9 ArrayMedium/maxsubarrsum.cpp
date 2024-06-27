#include<bits/stdc++.h>
using namespace std;

//kadane's algo
int optimal(int a[] , int n){
    int maxsum = INT_MIN ;        // sc  o(1)
    int sum = 0;
    int start = 0 ;
    int ansStart = -1 , ansEnd = -1;
    for (int i=0 ;i<n ;i++ ){     //tc o(n)
        if(sum == 0) start = i ;
        sum += a[i] ;
        if (sum > maxsum){
            maxsum = sum ; 
            ansStart = start ;
            ansEnd = i ;
        }
        if(sum < 0){
            sum = 0 ;
        }
    }
    cout << ansStart << "," << ansEnd << endl;
    return maxsum ;
    
}

int brute(int a[] ,int n){
    int maxsum = INT_MIN ;
    for(int i=0;i<n ;i++){    // tc o(n^2)
        int sum = 0;
        for(int j=i ;j<n ;j++){
            sum += a[j] ;
            maxsum =max (maxsum ,sum) ;
        }
    }
    return maxsum ;
}

int main(){
    int n =8 ;
    int a[n] ={-2,-3,4,-1,-2,1,5,-3} ;

    cout << brute(a , n) << endl;

    cout << optimal(a,n) << endl ;
}