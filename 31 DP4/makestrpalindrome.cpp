#include <bits/stdc++.h>
using namespace std;
/*
Problem:
Minimum insertions to make string palindrome.
*/

// TC: O(n²) | SC: O(n²)
//? min insertions to make string palindrome

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


int makestrpalindrome(string &s){

    int n = s.size();
    string rev = s ;
    reverse(rev.begin() , rev.end())  ;

    return n- lcsubsequenceOptimal(s , rev) ;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "Smilodon";

    cout << makestrpalindrome(s) << endl ;

    return 0;
}
