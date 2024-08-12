#include<bits/stdc++.h>
using namespace std ;

//row wise sorted arr
//n,m -> odd

int ubound(vector<int> &a ,int n ,int target){
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

int howMany(vector<vector<int>> &v ,int n ,int m ,int mid){
    int cnt = 0 ;

    for(int i= 0 ;i<n ;i++){         // o)(n*logm)
        cnt += ubound(v[i] , m ,mid) ;
    }
    return cnt ;
}

int binary(vector<vector<int>> &v ,int n, int m){
    int low = INT_MAX , high = INT_MIN ;
    for(int i= 0 ;i<n ;i++){
        low = min(low , v[i][0] ) ;
        high = max(high , v[i][m-1] ) ;
    }
    int req = (n*m) /2 ;

    while(low <= high){            // tc : o(log(1e9) * (n*logm))
        int mid = (low+high)/2 ;
        int cnt = howMany(v ,n,m,mid) ;
        if(cnt > req ){
            high = mid-1 ;
        }
        else{
            low = mid +1 ;
        }
    }
    return low ;
}

int main(){
    vector<vector<int>>v = {
        {1,5,7,9,11},
        {2,3,4,5,10},
        {9,10,12,14,16}
    } ;

    vector<vector<int>> v2 = {
    {1},
    {2},
    {8},
    {8},
    {1},
    {13},
    {14},
    {15},
    {12},
    {17},
    {18}
};

    int n = v2.size() ;
    int m = v2.at(0).size() ;

    cout << binary(v2,n,m) << endl; 

}