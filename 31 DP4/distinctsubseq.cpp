#include <bits/stdc++.h>
using namespace std;

int distinctsubseqOptimal(string s, string t){
    int n = s.size() ;
    int m = t.size() ;
    vector<int> prev(m+1, 0) , curr(m+1, 0);

    for(int j = 1 ; j <= m ; j++) prev[j] = 0 ;
    prev[0] = curr[0] = 1 ;   

    for(int i = 1 ; i <= n ; i++){
        for(int j =1 ; j<= m ; j++){

            long long take = 0, notake = 0;
            if (s[i-1] == t[j-1]) take = prev[j - 1];

            notake = prev[j];

            curr[j] = take + notake;      
        }
        prev = curr ;
    }
    return prev[m] ;
}

int distinctsubseqTab(string s , string t){
    int n = s.size() ;
    int m = t.size() ;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int j = 1 ; j <= m ; j++) dp[0][j] = 0 ;
    for(int i = 0 ; i <= n ; i++) dp[i][0] = 1 ; 

    for(int i = 1 ; i <= n ; i++){
        for(int j =1 ; j<= m ; j++){

            long long take = 0, notake = 0;
            if (s[i-1] == t[j-1]) take = dp[i - 1][j - 1];

            notake = dp[i - 1][j];

            dp[i][j] = take + notake;      
        }
    }
    return dp[n][m] ;
}

int distinctsubseqHelper(int idx1, int idx2  , string s1 , string s2 ,vector<vector<int>> &memo){
    
    if (idx2 < 0) return 1;
    if (idx1 < 0) return 0;

    if (memo[idx1][idx2] != -1)
        return memo[idx1][idx2];

    long long take = 0, notake = 0;

    if (s1[idx1] == s2[idx2]) {
        take = distinctsubseqHelper(idx1 - 1, idx2 - 1, s1, s2, memo);
    }

    notake = distinctsubseqHelper(idx1 - 1, idx2, s1, s2, memo);

    return memo[idx1][idx2] = take + notake;      
}

int distinctsubseqMemo(string s1 , string s2){

    int n = s1.size() ;
    int m = s2.size() ;
    vector<vector<int>> memo(n, vector<int>(m, -1));
    return distinctsubseqHelper(n-1 , m-1,s1 , s2 , memo);     
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1 = "Smilodon";
    string s2("monday");

    cout << distinctsubseqMemo(s1 , s2) << endl ;
    cout << distinctsubseqTab(s1 , s2) << endl ;
    cout << distinctsubseqOptimal(s1 , s2) << endl ;

    return 0;
}

