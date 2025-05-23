#include<bits/stdc++.h>
using namespace std;

//swaping array
void rev(int a[] , int n){
    int i;
    for(i=0;i<n/2;i++){
        swap(a[i],a[n-i-1]);
    }
    for(i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void rev2(int a[], int n , int l ){
    if(l==n/2){
        for(l=0;l<n;l++){
            cout << a[l] << " ";
        }
        cout << endl;
        return ;
    }
    swap(a[l],a[n-l-1]);
    rev2(a,n ,l+1 );
}

void drome( string &s ,int l ){ //parameterised
    int len=s.size();
    if(l==len/2){
        cout << s << " ";
        return ;
    }
    swap(s[l],s[len-1-l]);
    drome( s ,l+1 );
}

bool drome2( string s ,int l ){ //functional
    int len=s.size();
    if(l>=len/2) return true; //o(n/2)
    if(s[l]!=s[len-1-l]) return false ;
    return drome2( s ,l+1 );
}

int main(){
    int n =6;
    int l=0;
    int a[n]={1,5,2,3,4,2};
    rev(a,n);
    rev2(a ,n ,l );

    string s ;
    getline(cin ,s);
    string dup =s;
    drome(s ,l);
    if(dup==s)cout << "true " << endl; 
    else cout << "false " <<  endl;//palindrome
    drome2(s ,l); 
    cout << drome2(s,l) ;
}    