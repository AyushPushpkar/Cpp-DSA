#include<bits/stdc++.h>
using namespace std;

int sum2(int &n1,int &n2){ //pbr
    int n3=n1+n2;
    return n3;
}

int sum(int n1,int n2){   //pbv
    int n3=n1+n2;
    return n3;
}

int main(){
    int n1,n2;
    cin >> n1 >>n2 ;
    int res = sum(n1,n2);
    cout << res ;

    sum2(n1,n2);
    return 0;
}