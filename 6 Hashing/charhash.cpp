#include<bits/stdc++.h>
using namespace std;

void morehash(string s){
    int hash[256]={0};

    //precompute
    for(int i =0;i<s.size();i++){
        hash[s[i]]+=1; //ASCII value
    }
    
    int q2;
    cin >> q2;
    while(q2--){
        char c;
        cin >> c;

        //fetch
        cout << hash[c] << endl;
    }
}

int main(){
    string s;
    getline(cin ,s);

//pre compute
    int hash[26]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']+=1;
    }

    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c; 

        //fetch
        cout<< hash[c-'a'] << endl ; 
    }
    cout << endl ;

    morehash(s);
}