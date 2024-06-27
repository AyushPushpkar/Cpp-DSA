#include<bits/stdc++.h>
using namespace std;

void dosmthg(int arr[] , int n){
    arr[0] += 100 ;
    cout << arr[0]<< endl ;
}

int main(){
    int n=5 ,i;
    int arr[n];
    for(i=0;i<n;i++){
        cin >> arr[i] ;
    }
    dosmthg(arr,n);
    cout << arr[0]<< endl ;
    return 0;
}