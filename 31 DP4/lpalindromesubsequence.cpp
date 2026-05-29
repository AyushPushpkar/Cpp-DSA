#include <bits/stdc++.h>
using namespace std;

int lcsubsequenceOptimal(string s1 , string s2){
    int n = s1.size() ;
    int m = s2.size() ;
    vector<int> prev(m+1, 0);
    vector<int> curr(m+1, 0);

    for(int i = 1 ; i <= n ; i++){
        for(int j =1 ; j<= m ; j++){

           if (s1[i-1] == s2[j-1]) curr[j] = 1 + prev[j-1];

           else curr[j] = max( prev[j], curr[j-1] ) ;
        }
        prev = curr ;
    }

    return prev[m] ;
}

int lpsubsequence(string &s){

    string rev = s ;
    reverse(rev.begin() , rev.end())  ;

    return lcsubsequenceOptimal(s , rev) ;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "Smilodon";

    cout << lpsubsequence(s) << endl ;

    return 0;
}
