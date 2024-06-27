#include<bits/stdc++.h>
using namespace std;

void print(int n, string s , int cnt){
    if (cnt==n+1) //base
    return;
    cout << s << " " ;
    cnt+=1 ;
    print(n,s,cnt);// tc:o(n)  sc:o(n) stack space
}

void print2(int n ,int cnt){
    if(cnt==n+1)
    return;
    cout << cnt << " ";
    print2(n,cnt+1);
}

void print3(int n ,int cnt2){
    if(cnt2<1)
    return;
    cout << cnt2 << " ";
    print3(n,cnt2-1);
}

void print4(int n ){
    if(n<1)
    return;
    print4(n-1);
    cout << n << " ";
}

void print5(int n ,int cnt){
    if(cnt>n)
    return;
    print5(n,cnt+1);
    cout << cnt << " ";
}

int main(){
    string s;
    int cnt =1 ,n ;
    cin >> s >> n ;
    int cnt2 =n;
    print(n, s ,cnt);
    cout << endl;
    print2(n,cnt);
    cout << endl;
    print3(n,cnt2);
    cout << endl;
    print4(n);
    cout << endl;
    print5(n,cnt);
    return 0;
}