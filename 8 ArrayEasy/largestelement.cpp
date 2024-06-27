#include<bits/stdc++.h>
using namespace std;

void ssmallest(int a[] , int n){
    int small =a[0] , ssmall = INT_MAX;
    for(int i=0;i <n ;i++){    //o(n)
        if(a[i]<small){
            ssmall = small;
            small = a[i];
        }
        else if(a[i]>small && a[i]<ssmall){
            ssmall = a[i];
        }
    }
    cout << small << " " << ssmall << endl ;
}

void optimal(int a[] , int n){
    int flarge =a[0] , slarge = INT_MIN;
    for(int i=0;i <n ;i++){
        if(a[i]>flarge){
            slarge = flarge;
            flarge = a[i];
        }
        else if(a[i]<flarge && a[i]>slarge){
            slarge = a[i];
        }
    }
    cout << flarge << " " << slarge << endl ;
}

void second(int a[],int n, int large){
    int seclarge = -1;
    for(int i=0 ; i<n ; i++){    //o(n)
        if(a[i]>seclarge && a[i]!=large){
            seclarge = a[i];
        }
    }
    cout << seclarge << endl ;
}

void largest(int a[],int n){
    int large = a[0];
    for(int i=0; i<n ;i++){   //o(n)
        if(a[i]>large){
            large =a[i];
        }
    }
    cout << large << endl;
    second(a,n,large);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0 ; i<n ; i++){
        cin >> a[i] ;
    }
    largest(a,n);

    optimal(a,n);

    ssmallest(a,n);
}