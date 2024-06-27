#include<bits/stdc++.h>
using namespace std;

//longer prefix match
//greater but closest
//rest in sorted order
string optimal(string str , int n){
    int index = -1;
    for(int i =n-2 ;i>=0 ; i--){     //o(n)
        if(str[i]<str[i+1]){
            index = i ;
            break;
        }
    }
    if(index == -1){
        reverse(str.begin(),str.end());
        return str ;
    }

    for(int i =n-1 ;i>index ; i--){  //o(n)
        if(str[i]>str[index]){
            swap(str[i],str[index]);
            break;
        }
    }

    reverse(str.begin()+index+1,str.end());  //o(n)
    // sort(str.begin()+index+1,str.end());
    return str ;
}

int main(){
    string str="2154300";
    int n = str.size() ;

    //brute tc : o(n! * n)

    // better  c++ stl

    cout << optimal(str,n);
    
}