#include<bits/stdc++.h>
using namespace std ;

//without extra space

//shell sort ;
//gap method ;
void swapifGreater(int a[] ,int arr[] ,int ind1 ,int ind2){
    if(a[ind1] > arr[ind2]){
        swap(a[ind1],arr[ind2]) ;
    }
}

void optimal2(int a[],int n, int arr[], int m){
    int len = n+m ;
    int gap = (len/2) + (len%2) ;

    while(gap>0){          //  o(log2(n+m))
        int left =0 ;
        int right = left + gap ;        
        while(right< len){       // o(n+m)
            if(left < n && right >= n){
                swapifGreater(a,arr,left,right -n) ;
            }
            else if(left >= n){
                swapifGreater(arr,arr ,left-n,right-n) ;
            }
            else{
                swapifGreater(a,a,left,right) ;
            }
            left++ ;
            right++ ;
        }
        if(gap == 1)break;
        else{
            gap = (gap/2) + (gap%2) ;
        }
    }
    
    for(int i=0;i<n;i++){
        cout << a[i] <<  " " ;
    }
    cout << endl ;
    for(int i=0;i<m;i++){
        cout << arr[i] << " " ;
    }
    cout << endl ;
}

void optimal(int a[],int n, int arr[], int m){
    int p1=n-1 ,p2=0;

    while(p1>=0 && p2<m){            // o(min(n,m))
        if(a[p1] >  arr[p2]){
            swap(a[p1] ,arr[p2]) ;
            p1-- ;
            p2++ ;
        }
        else{
            break;
        }
    }
    sort(a,a+n);           // o(2nlogn)
    sort(arr,arr+m) ;
    
    for(int i=0;i<n;i++){
        cout << a[i] <<  " " ;
    }
    cout << endl ;
    for(int i=0;i<m;i++){
        cout << arr[i] << " " ;
    }
    cout << endl ;
}

void brute(int a[],int n, int arr[], int m){
    vector<int>temp ;    // sc : o(n+m)
    int p1=0 ,p2=0;

    while(p1<n && p2<m){            // o(n+m)
        if(a[p1] <  arr[p2]){
            temp.push_back(a[p1]) ;
            p1++ ;
        }
        else if(a[p1]>arr[p2]){
            temp.push_back(arr[p2]);
            p2++;
        }
        else{
            temp.push_back(a[p1]) ;
            temp.push_back(arr[p2]) ;
            p1++ ;
            p2++;
        }
    }
    while(p1<n ){
        temp.push_back(a[p1]) ;
        p1++ ;
    }
    while(p2<m){
        temp.push_back(arr[p2]);
        p2++;
    }

    for(int i=0;i<n+m;i++){            //  o(n+m)
        if(i<n) a[i] = temp[i] ;
        else arr[i-n] = temp[i] ;
    }

    for(int i=0;i<n;i++){
        cout << a[i] <<  " " ;
    }
    cout << endl ;
    for(int i=0;i<m;i++){
        cout << arr[i] << " " ;
    }
    cout << endl ;
}

int main(){
    int n= 4;
    int a[n] = {1,3,5,7};
    int m= 5 ;
    int arr[m] = {0,2,6,8,9} ;

    // brute(a,n,arr,m) ;

    optimal2(a,n,arr,m) ;
}