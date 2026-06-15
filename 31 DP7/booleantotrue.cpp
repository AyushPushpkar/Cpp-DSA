#include <bits/stdc++.h>
using namespace std;
/*
Problem:
A boolean expression is an expression that evaluates to either true or false. 
It can be in one of the following shapes:

't' that evaluates to true.
'f' that evaluates to false.
'!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
'&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions where n >= 1.
'|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions where n >= 1.

Given a string expression that represents a boolean expression, 
return the evaluation of that expression.

*/

int parseBoolExprTab(string expression) {

    int n = expression.size() ;

    vector<vector<vector<int>>> dp(n ,vector<vector<int>>(n , vector<int>(2 , 0))) ;

    for(int i = 0 ; i < n ; i += 2){
        dp[i][i][1] = (expression[i] == 'T') ;
        dp[i][i][0] = (expression[i] == 'F') ;
    }

    for(int start = n-1 ; start >= 0 ; start--){
        for(int end = start+1 ; end < n ; end++){
            for(int isTrue = 0 ; isTrue <= 1 ; isTrue++){

                long long ways = 0 ;

                for(int idx = start+1 ; idx < end ; idx += 2){

                    int lT = dp[start][idx-1][1] ;
                    int lF = dp[start][idx-1][0] ;
                    int rT = dp[idx+1][end][1] ;
                    int rF = dp[idx+1][end][0] ;

                    char op = expression[idx] ;

                    if(op == '&'){
                        if(isTrue == 1) ways += 1LL * lT * rT ;
                        else ways += 1LL * lT * rF +  1LL * lF * rF ;               
                    }
                    else if(op == '|'){
                        if(isTrue == 1)ways += 1LL * lT * rT + 1LL * lT * rF +1LL * lF * rT ;                                                                        
                        else ways += 1LL * lF * rF ;                            
                    }
                    else if(op == '^'){
                        if(isTrue == 1) ways += 1LL * lT * rF + 1LL * lF * rT ;                                                              
                        else ways += 1LL * lT * rT + 1LL * lF * rF ;
                    }
                }
                dp[start][end][isTrue] = ways ;
            }
        }
    }

    return dp[0][n-1][1] ;
}

int parseBoolExprHelper(int start, int end, int isTrue, string &expression, vector<vector<vector<int>>> &memo) {

    if (start > end) return 0;

    if (start == end) {
        if (isTrue)
            return expression[start] == 'T';
        else
            return expression[start] == 'F';
    }

    if (memo[start][end][isTrue] != -1)
        return memo[start][end][isTrue];

    long long ways = 0;

    for (int idx = start + 1; idx < end; idx += 2) {

        int lT = parseBoolExprHelper(start, idx - 1, 1, expression, memo);
        int lF = parseBoolExprHelper(start, idx - 1, 0, expression, memo);
        int rT = parseBoolExprHelper(idx + 1, end, 1, expression, memo);
        int rF = parseBoolExprHelper(idx + 1, end, 0, expression, memo);

        char op = expression[idx];

        if (op == '&') {
            if (isTrue) ways += 1LL * lT * rT;
            else ways += 1LL * lT * rF + 1LL * lF * rT + 1LL * lF * rF;
        }
        else if (op == '|') {
            if (isTrue) ways += 1LL * lT * rT + 1LL * lT * rF + 1LL * lF * rT;
            else ways += 1LL * lF * rF;
        }
        else if (op == '^') {
            if (isTrue) ways += 1LL * lT * rF + 1LL * lF * rT;
            else ways += 1LL * lT * rT + 1LL * lF * rF;
        }
    }

    return memo[start][end][isTrue] = ways;
}

int parseBoolExprMEMO(string expression){
    int n = expression.size() ;

    if(n <=  2) return 0 ; 
    vector<vector<vector<int>>> memo(n , vector<vector<int>> (n , vector<int>(2, -1))) ;

    return parseBoolExprHelper(0 , n-1 ,1,  expression , memo) ; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string expression = "T|F&T" ; 

    cout << parseBoolExprMEMO(expression) <<endl ; 
    return 0;
}
