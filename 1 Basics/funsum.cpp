#include<bits/stdc++.h>
using namespace std;

int sum(int n1,int n2){
    int n3=n1+n2;
    return n3;
}

int main(){
    int n1,n2;
    cin >> n1 >>n2 ;
    int res = sum(n1,n2);
    cout << res ;
    return 0;
}