#include <bits/stdc++.h>
using namespace std;
/*
Problem:
Largest string chain

*/

static bool comp(string &s1 , string &s2 ) {
    return s1.size() < s2.size() ;
}

bool compare(string s1 , string s2){
    if(s1.size() != s2.size() +1 ) return false ; 
    int p1 = 0  , p2 = 0 ; 

    while(p1 < s1.size()){
        if(s1[p1] == s2[p2] ){
            p1++ ; 
            p2++ ;
        }
        else p1++ ; 
    }

    if(p1 == s1.size() && p2 == s2.size()) return true ; 
    return false ; 
}


int longeststrchain(vector<string>& words ) {
    int n = words.size();
    vector<int> dp(n,1) ;
    int maxi = 1 ;
     
    sort(words.begin() , words.end() , comp) ;

    for (int idx = 0; idx < n; idx++) {
        for (int prev = 0; prev < idx; prev++) {

            if (compare(words[idx] , words[prev]) && dp[idx] < 1 + dp[prev]) {
                dp[idx] = 1 + dp[prev];
            }
        }
        maxi = max(maxi , dp[idx]) ;
    }

    return maxi ; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> words =  { "a","b","ba","bca","bda","bdca"} ; 

    cout <<  longeststrchain(words) ;

    return 0;
}
