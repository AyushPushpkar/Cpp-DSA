#include <bits/stdc++.h>
using namespace std;

int lcsubsequenceOptimal(string s1 , string s2){
    int n = s1.size() ;
    int m = s2.size() ;
    vector<int> prev(m+1, 0);
    vector<int> curr(m+1, 0);

    for(int i = 0 ; i <= m ; i++) prev[i] = 0 ;
    curr[0] = 0 ;   

    for(int i = 1 ; i <= n ; i++){
        for(int j =1 ; j<= m ; j++){

           if (s1[i-1] == s2[j-1]) curr[j] = 1 + prev[j-1];

           else curr[j] = max( prev[j], curr[j-1] ) ;
        }
        prev = curr ;
    }

    return prev[m] ;
}

int lcsubsequenceTab(string s1 , string s2){
    int n = s1.size() ;
    int m = s2.size() ;
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    for(int j = 0 ; j <= m ; j++) dp[0][j] = 0 ;
    for(int i = 0 ; i <= n ; i++) dp[i][0] = 0 ;   

    for(int i = 1 ; i <= n ; i++){
        for(int j =1 ; j<= m ; j++){

           if (s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i - 1][j-1];

           else dp[i][j] = max( dp[i-1][j], dp[i][j-1] ) ;
        }
    }

    return dp[n][m] ;
}

int lcsubsequenceHelper(int idx1, int idx2  , string s1 , string s2 ,vector<vector<int>> &memo){
    
    if (idx1 < 0 || idx2 < 0)
        return 0;

    if (memo[idx1][idx2] != -1)
        return memo[idx1][idx2];

    if (s1[idx1] == s2[idx2]) {
        return memo[idx1][idx2] =
            1 + lcsubsequenceHelper(idx1 - 1, idx2 - 1, s1, s2, memo);
    }

    return memo[idx1][idx2] = max(
        lcsubsequenceHelper(idx1 - 1, idx2, s1, s2, memo),
        lcsubsequenceHelper(idx1, idx2 - 1, s1, s2, memo)
    );                 
}

int lcsubsequenceMemo(string s1 , string s2){

    int n = s1.size() ;
    int m = s2.size() ;
    vector<vector<int>> memo(n, vector<int>(m, -1));
    return lcsubsequenceHelper(n-1 , m-1,s1 , s2 , memo);     
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1 = "Smilodon";
    string s2("monday");

    cout << lcsubsequenceMemo(s1 , s2) << endl ;
    cout << lcsubsequenceTab(s1 , s2) << endl ;
    cout << lcsubsequenceOptimal(s1 , s2) << endl ;

    return 0;
}
