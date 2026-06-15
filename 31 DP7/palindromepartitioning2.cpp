#include <bits/stdc++.h>
using namespace std;
/*
Problem:
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.
*/

bool isPalindrome(int i , int j , string s ){
    while(i<j){
        if(s[i] != s[j] ) return  false ; 
        i++ ; 
        j--;
    }
    return true ; 
}

int minCutTab(string s){
    int n = s.size() ; 
    vector<int> dp(n+1 , 0) ;

    for(int i = n-1 ; i >=0 ; i--){
        int mini =  INT_MAX ; 

        for (int j = i; j < n; j++) {
            if(isPalindrome(i , j , s)) mini = min(mini , 1 + dp[j+1]) ;
        }
        dp[i] = mini ; 
    }

    return dp[0] - 1; 
     
}


int findMin(int start, int n, string s , vector<int>& memo) {

    if (start == n) return 0;

    if(memo[start] != -1 ) return memo[start] ; 

    // string temp = "" ;

    int mini =  INT_MAX ; 

    for (int k = start; k < n; k++) {

        // temp += s[k] ;
        if(isPalindrome(start , k , s)){
            int cost = 1 + findMin(k+1, n,s , memo) ;
            mini = min(mini , cost) ;
        }
    }

    return memo[start] = mini;
}

int minCutMemo(string s){
    int n = s.size() ;

    vector<int> memo(n , -1) ;

    return findMin(0 , n , s , memo) -1; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "bababcbadcede" ;

    cout << minCutMemo(s) <<endl ; 
    return 0;
}
