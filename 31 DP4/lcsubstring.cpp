#include <bits/stdc++.h>
using namespace std;
/*
Problem:
Longest common substring - find longest contiguous substring present in both strings.
*/

// TC: O(m × n) | SC: O(m × n)
int lcsubstringOptimal(string s1 , string s2){
    int n = s1.size() ;
    int m = s2.size() ;
    vector<int> prev(m+1, 0);
    vector<int> curr(m+1, 0);

    int ans = 0 ;

    for(int i = 1 ; i <= n ; i++){
        for(int j =1 ; j<= m ; j++){

           if (s1[i-1] == s2[j-1]) curr[j] = 1 + prev[j-1];

           else curr[j] = 0 ;

           ans = max(ans , curr[j]) ;
        }
        prev = curr ;
    }

    return ans ;
}

int lcsubstringTab(string s1 , string s2){
    int n = s1.size() ;
    int m = s2.size() ;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int ans = 0; 

    for(int i = 1 ; i <= n ; i++){
        for(int j =1 ; j<= m ; j++){

           if (s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i - 1][j-1];

           ans = max(ans , dp[i][j]) ;
        }
    }

    return ans ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1 = "Smilodon";
    string s2("monday");

    cout << lcsubstringTab(s1 , s2) << endl ;
    cout << lcsubstringOptimal(s1 , s2) << endl ;

    return 0;
}
