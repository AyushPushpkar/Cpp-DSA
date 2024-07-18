#include<bits/stdc++.h>
using namespace std ;

pair<int,int> iterative(int a[] ,int n,int target){
    int low = 0 , high = n-1 ;
    int first = -1 ,last = -1 ;

    while(low <= high){
        int mid = (low+high)/2 ;
        if(a[mid] == target) {
            first = mid ;
            high = mid -1 ;
        } 
        else if ( a[mid] < target){
            low = mid+1 ;
        }
        else{
            high = mid-1 ;
        }
    }

    low = 0 ;
    high = n-1 ;
    while(low <= high){
        int mid = (low+high)/2 ;
        if(a[mid] == target) {
            last = mid ;
            low = mid +1 ;
        } 
        else if ( a[mid] < target){
            low = mid+1 ;
        }
        else{
            high = mid-1 ;
        }
    }
    return {first,last} ;
    
}

int ubound(int a[] ,int n ,int target){
    int ans = n ;   //tc  :  o(log2(n))

    int low = 0 , high = n-1 ;

    while(low <= high){
        int mid = (low+high)/2 ;
        if(a[mid] > target){
            ans = mid ;
            high = mid - 1 ;
        } 
        else {
            low = mid+1 ;
        }
    }
    return ans  ;
}

int lbound(int a[] ,int n ,int target){
    int ans = n ;   //tc  :  o(log2(n))

    int low = 0 , high = n-1 ;

    while(low <= high){
        int mid = (low+high)/2 ;
        if(a[mid] >= target){
            ans = mid ;
            high = mid - 1 ;
        } 
        else {
            low = mid+1 ;
        }
    }
    return ans  ;
}

void occur(int a[] ,int n ,int x){
    vector<pair<int,int>> ans ;
    int lb = lbound(a,n,x) ;

    if( lb == n || a[lb] != x){
        ans.push_back({-1,-1}) ;
    }
    else{
        ans.push_back({lb , ubound(a,n,x) -1}) ;
    }

    for(auto it : ans){
        cout << it.first << " , " << it.second << endl ;
    }
    
}

int cntoccur(pair<int,int> it){
    int first = it.first ;
    int last = it.second ;

    if(first == -1)return 0 ;

    int cnt = last -first + 1 ;
    return cnt ;
}

int main(){
    int n = 8 ;
    int a[n] = {2,4,6,8,8,8,11,13} ;

    int x ;
    cin >> x;

    //lenior search o(n)
    //sorted
    //better is o(logn)  so binary

    occur(a,n,x) ;  // tc : o(logn) 

    auto it = iterative(a,n,x) ;
    cout << it.first << " , " << it.second << endl ;

    cout << cntoccur(it) ;

}