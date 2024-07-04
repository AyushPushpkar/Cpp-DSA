#include<bits/stdc++.h>
using namespace std ;

//dutch national flag algo
//3 pointer
// [0 ... low-1] = 0
// [low ...mid-1 ] = 1
//[high+1 ... n-1] =2
void optimal(int a[] , int n){
    int low = 0 ,mid = 0 , high =n-1 ;  //sc o(1)

    while(mid<=high){         //tc : o(n)
        if(a[mid]==0){
            swap(a[mid],a[low]);
            mid++;
            low++;
        }
        else if(a[mid] == 1) mid ++ ;
        else {
            swap(a[mid],a[high]);
            high -- ;
        }
    }
    for(int i=0;i<n ;i++){
        cout << a[i] << " " ;
    }
    cout << endl ;
}

void better(int a[], int n){
    int cnt=0 ,cnt1=0 ,cnt2=0 ;      //sc o(1)

    for(int i=0;i<n;i++){            // o(n)
        if(a[i]==0) cnt ++ ;
        else if(a[i]==1) cnt1++ ;
        else cnt2 ++ ;
    }
    for(int i=0 ; i<cnt ;i++) a[i]=0 ;     // o(n)
    for(int i=cnt ; i<cnt+cnt1 ; i++) a[i]=1 ;
    for(int i=cnt+cnt1 ; i<n ;i++) a[i]=2 ;

    for(int i=0;i<n ;i++){
        cout << a[i] << " " ;
    }
    cout << endl ;
}

int main(){
    int n =12;
    int a[n] = {0,1,2,0,1,2,1,2,0,0,0,1};

    //brute merge  or quick sort

    // better(a,n);

    optimal(a,n);
}