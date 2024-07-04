#include<bits/stdc++.h>
using namespace std;

void optimal2(vector<vector<int>>& v,int n){
    //               sc : o(1)

    for (int i = 0; i < n; i++) {       // o(n)
        for (int j = i+1; j < n; j++) {      //o(n/2)
            swap(v[i][j],v[j][i]);
        }
        reverse(v[i].begin(),v[i].end());   // o(n)
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j] << " " ;
        }
        cout << endl ;
    }
}

void optimal(vector<vector<int>>& v,int n){

    for (int i = 0; i < n; i++) {       //tc : o(n^2)
        for (int j = 0; j < n; j++) {
            if(i<j){
                swap(v[i][j],v[j][i]);
            }
        }
    }
    for (int i = 0; i < n; i++) {       //tc : o(n * n/2)
        for (int j = 0; j < n/2; j++) {
            swap(v[i][j],v[i][n-1-j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j] << " " ;
        }
        cout << endl ;
    }
}

void brute(vector<vector<int>>& v,int n,int m){
    vector<vector<int>> ans(m,vector<int>(n)) ;  //sc o(n^2)

    for (int i = 0; i < n; i++) {       //tc : o(n^2)
        for (int j = 0; j < m; j++) {
            ans[j][n-i-1] = v[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " " ;
        }
        cout << endl ;
    }
}

int main(){
    int n=4,m=4 ;
    vector<vector<int>> v ={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    // brute(v,n,m) ;

    // optimal(v,n);
    optimal2(v,n);
}