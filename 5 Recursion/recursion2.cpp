#include<bits/stdc++.h>
using namespace std;


// sum 1st n natural numbers
void sum(int n , int &add){ //parameterised
    if(n<1)
    return ;
    add= add + n;
    sum(n-1 , add);
}    

void sum2(int n , int add){ //parameterised
    if(n<1){
        cout << add ;
        return;
    }
    sum2(n-1 , add + n);
}    

int sum3(int n){ //functional
    if(n==0)
    return 0;
    else return n+sum3(n-1);
}

int main(){
    int n ,add=0;
    cin >> n ;
    sum2(n,add);
    cout << endl;
    sum3(n);
    cout << sum3(n) << "#" << endl;
    sum(n ,add);
    cout << add << "&" << endl;
    return 0;
}