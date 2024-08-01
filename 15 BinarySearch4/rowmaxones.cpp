#include<bits/stdc++.h>
using namespace std ;

//find the row with max 1's
//if same 1's smallest row

int lbound(vector<int>a ,int n ,int target){
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
    return ans ; 
}

int binary(vector<vector<int>> &v ,int n, int m){
    int index = -1 ;
    int maxCnt = 0 ;      //sc : o(1)

    for(int i=0 ;i<n ;i++){        //tc : o(n*logm)
        int cntRow = m - lbound(v[i], m , 1);
        if(cntRow > maxCnt){
            maxCnt = cntRow ;
            index = i ;
        }
    }
    return index ;
}

int brute(vector<vector<int>> &v ,int n, int m){
    int index = -1 ;
    int maxCnt = INT_MIN ;      //sc : o(1)

    for(int i=0 ;i<n ;i++){        //tc : o(n*m)
        int cntRow = 0 ;
        for(int j=0;j<m;j++){
            cntRow += v[i][j] ;
        }
        if(cntRow > maxCnt){
            maxCnt = cntRow ;
            index = i ;
        }
    }
    return index ;
}

int main(){
    vector<vector<int>>v = {
        {0,0,1,1,1},
        {0,0,0,0,0},
        {0,1,1,1,1},
        {0,0,0,0,0},
        {0,1,1,1,1}
    } ;

    int n = v.size() ;
    int m = v.at(0).size() ;

    cout << brute(v,n,m) << endl; 

    cout << binary(v,n,m) << endl; 

}