#include<bits/stdc++.h>
using namespace std;

int main(){
    int age;
    cin >> age ;
    if(age>=18){
        cout << "you are an adult!";
    }
    else if(age <18 && age >= 12){
        cout << "you are a teenager!";
    }
    else{
        cout << "you are a child!";
    }
    return 0;
}