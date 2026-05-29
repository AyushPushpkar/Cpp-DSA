#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> lcsubsequenceTab(int& n ,int& m , string &s1 , string &s2){
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    for(int i = 0 ; i <= m ; i++) dp[0][i] = 0 ;
    for(int i = 0 ; i <= n ; i++) dp[i][0] = 0 ;   

    // tc : o(n * m)
    for(int i = 1 ; i <= n ; i++){
        for(int j =1 ; j<= m ; j++){

           if (s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i - 1][j-1];

           else dp[i][j] = max( dp[i-1][j], dp[i][j-1] ) ;
        }
    }

    return dp ;
}

string lcsubsequence(string &s1 , string &s2){
    int n = s1.size() ;
    int m = s2.size() ;

    vector<vector<int>> dp = lcsubsequenceTab(n , m ,s1 , s2) ;

    vector<char> ans(dp[n][m]) ;
    int idx = dp[n][m] -1 ;

    // tc : o(n + m)
    int i = n ,  j = m ;
    while (i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            ans[idx] = s1[i-1] ;
            idx-- ;
            i = i-1 ; 
            j = j-1 ;
        }
        else if(dp[i-1][j] >= dp[i][j-1])i = i-1 ; 
        else j = j-1 ; 
    }

    string lcs(ans.begin(), ans.end());

    // string lcs = "";
    // for (auto it : ans) lcs.push_back(it);
    // for (auto it : ans) lcs.append(1, it);

    return lcs ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1 = "Smilodon";
    string s2("monday");

    cout << lcsubsequence(s1 , s2) << endl ;

    return 0;
}
