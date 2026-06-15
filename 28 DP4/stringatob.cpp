#include <bits/stdc++.h>
using namespace std;
/*
Problem:
Minimum steps transforming string A to B (insert, delete, replace operations).
*/

// TC: O(m × n) | SC: O(m × n)
//? min deletion/insertion 

int lcsubsequenceOptimal(int &n , int& m , string &s1 , string &s2){

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

int stringAtoB(string &s1 , string &s2){
    int n = s1.size() ;
    int m = s2.size() ;
    return n + m - 2*lcsubsequenceOptimal(n,m,s1,s2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1 = "Smilodon";
    string s2("monday");

    cout << stringAtoB(s1 , s2) << endl ;

    return 0;
}
