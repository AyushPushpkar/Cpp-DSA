#include<bits/stdc++.h>
using namespace std;

void print1(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        cout << "* " ;
        }
        cout << "\n";
    }
}

int main(){
    int i,t;
    cin >> t;
    for(i=0;i<t;i++){
    int n;
    cin >> n;
    print1(n);}
}