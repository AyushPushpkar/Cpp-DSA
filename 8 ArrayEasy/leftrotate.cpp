#include<bits/stdc++.h>
using namespace std;

void rightRotate(int k , int a[] , int n){

    reverse(a,a+n-k);     
    reverse(a+n-k,a+n);   
    reverse(a,a+n);    

    for(int i =0 ; i<n ;i++){
        cout << a[i] << " ";
    }
}

void optimalReverse2(int k , int a[] , int n){
    // tc :o(2n)    sc :o(1)

    reverse(a,a+k);     //o(k)
    reverse(a+k,a+n);   //o(n-k)
    reverse(a,a+n);     //o(n)

    for(int i =0 ; i<n ;i++){
        cout << a[i] << " ";
    }
}

void optimalReverse1(int k , int a[] , int n){
    // tc :o(n)    sc :o(1)

    for(int i=0;i<k/2 ; i++){   // o(k/2)
        swap(a[i],a[k-1-i]) ;
    }
    for(int i=k;i<(n+k)/2 ; i++){  // o((n-k)/2)
        swap(a[i],a[(n+k)-i-1]) ;
    }
    for(int i=0;i<n/2 ; i++){     //o(n/2)
        swap(a[i],a[n-1-i]) ;
    }
    for(int i =0 ; i<n ;i++){
        cout << a[i] << " ";
    }
}

void bykPlaceBrute(int k , int a[] , int n){
    vector<int> temp ;    // sc o(k)   tc o(n+k)
                          
    for(int i = 0 ;i<k; i++){     // o(k)
        temp.push_back(a[i]);
    }
    for( int i=k ; i<n ; i++){   //o(n-k)
        a[i-k]= a[i] ;
    }
    for( int i=n-k ; i<n ; i++){    //o(k)
        a[i]= temp[i-n+k] ;
    }

    for(int i =0 ; i<n ;i++){
        cout << a[i] << " ";
    }
}

void byOnePlace(int a[] , int n){

    int temp = a[0] ;              // sc o(1)
    for(int i =1 ; i<n  ; i++){    // tc o(n)  
        a[i-1] = a[i] ;             
    }
    a[n-1]= temp ;

    for(int i =0 ; i<n ;i++){
        cout << a[i] << " ";
    }
}

int main(){
    int n ;
    cin >> n ;
    int a[n]  ;
    for(int i=0 ; i<n ; i++){
        cin >> a[i] ;
    }

//    byOnePlace(a,n);   

    int k ;
    cin>> k ;
    k = k%n ;
    // bykPlaceBrute(k , a ,n);

    // optimalReverse1(k, a, n);
    // optimalReverse2(k, a, n);

    rightRotate(k ,a , n);
}