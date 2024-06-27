#include<bits/stdc++.h>
using namespace std;

int fac(int n){ //functional
    if(n==1) return 1;
    else return n*fac(n-1);
}

void fac2(int n,int mul){ //parameterised
    if(n<1){
        cout << mul << "#" << endl; ;
        return;
    }
    fac2(n-1,mul*n);
}

void fac3(int n,int mul){ //loop
    int i;
    for(i=n;i>=1;i--){
        mul=mul*i;
    }
    cout << mul << "&" << endl;
}

int main(){
    int n , mul=1;
    cin >> n;
    fac(n);
    cout << fac(n) << endl;
    fac2(n,mul);
    fac3(n,mul);
    return 0;
}