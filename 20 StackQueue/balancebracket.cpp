#include<bits/stdc++.h>
using namespace std ;

bool balancedParanthesis(string s ){  // tc : o(n)   // sc : o(n)
    int len = s.size() ;
    stack<int> st ;

    for(int i =0 ; i<len ;i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[' ){
            st.push(s[i]) ;
        }
        else{
            if(st.empty()) return false ;
            char ch = st.top() ;
            st.pop() ;
            if(!((s[i] == ')' && ch == '(') || (s[i] == ']' && ch == '[')
                    || (s[i] == '}' && ch == '{') )){   
                        return false ;
            }
        }
    }

    return st.empty() ;

}

int main(){
    string s = "({}[(){}])" ;
    cout << balancedParanthesis(s) ;
}