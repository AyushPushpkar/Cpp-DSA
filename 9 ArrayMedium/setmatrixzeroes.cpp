#include<bits/stdc++.h>
using namespace std;

void better(vector<vector<int>>& v,int n,int m){
    int col[m]={0};
    int row[n]={0};

    for (int i = 0; i < n; i++) {       //o(n*m)
        for (int j = 0; j < m; j++) {
            if(v[i][j] == 0){
                col[j]=1;
                row[i]=1;
            }
        }
    }
    for (int i = 0; i < n; i++) {       //o(n*m)
        for (int j = 0; j < m; j++) {
            if(col[j] == 1 || row[i]==1){
                v[i][j] = 0 ;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j] << " " ;
        }
        cout << endl ;
    }
}

void markRow(vector<vector<int>>& v,int m,int i){
     
    for (int j = 0; j < m; j++) {
       if(v[i][j] != 0){
            v[i][j] = -1 ;
        }
    }
}

void markCol(vector<vector<int>>& v,int n,int j){
    for (int i = 0; i < n; i++) {
       if(v[i][j] != 0){
            v[i][j] = -1 ;
        }
    }
}

void brute(vector<vector<int>>& v,int n,int m){
    //tc o(n^3)

    for (int i = 0; i < n; i++) {       //o((n*m)*(n+m))
        for (int j = 0; j < m; j++) {
            if(v[i][j] == 0){
                markRow(v,m,i);
                markCol(v,n,j);
            }
        }
    }
    for (int i = 0; i < n; i++) {       //o(n*m)
        for (int j = 0; j < m; j++) {
            if(v[i][j] == -1){
                v[i][j] = 0 ;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j] << " " ;
        }
        cout << endl ;
    }
}

int main(){
    int n=4,m=4 ;
    vector<vector<int>> v ={
        {1,1,1,1},
        {1,1,0,1},
        {1,1,0,1},
        {1,1,1,1}
    };

    // brute(v,n,m) ;

    better(v,n,m);
}