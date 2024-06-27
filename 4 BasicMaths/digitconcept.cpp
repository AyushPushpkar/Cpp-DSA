#include<bits/stdc++.h>
using namespace std;

void extractdigit(int n){
    int digit ,cnt=0 , rev=0;
    int dup =n;
    int sum=0;
    while(n>0){
        digit = n%10 ;
        cout << digit << " "; 
        n=n/10;
        cnt+=1;
        rev = (rev*10)+digit ;
        sum =sum+(digit*digit*digit);
    }cout << endl;
    cout << cnt << endl;
    cout << rev << "\n" ;
    if(rev==dup)
    cout << "true" << endl;//palindrome
    else
    cout << "false" << endl;

    if(sum==dup)
    cout << "true" << endl ;//Amstrong
    else
    cout << "false" << endl;
}

void count(int n){
    int cnt;
    cnt = log10(n)+1;
    cout << cnt ;
    //o(log10(n))
}

int main(){
    int n ;
    cin >> n ;
    extractdigit(n);
    count(n);
    return 0;
}