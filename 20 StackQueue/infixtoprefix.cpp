#include<bits/stdc++.h>
using namespace std ;

int priority(char ch){
    if(ch == '^') return 3 ;
    if(ch == '*' || ch == '/') return 2 ;
    if(ch == '+' || ch == '-') return 1 ;
    return -1 ;
}

string infixtoPrefix(string s){  
    int n = s.size() ;
    reverse(s.begin(), s.end()) ;   
    string ans = "" ;      // tc : o(3n)
    stack<int> st ;        // sc : o(n) + o(n)
    int i = 0 ;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }

    while (i<n){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9') ){
                ans += s[i] ;
        }
        else if (s[i] == '('){
            st.push(s[i]);
        }
        else if (s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top() ;
                st.pop() ;
            }
            st.pop() ;
        }
        else{
            if(s[i] == '^'){
                while(!st.empty() && priority(s[i]) <= priority(st.top())){
                    ans+= st.top() ;
                    st.pop() ;
                }  // can't store 2 powers in stack together
            }
            else{
                while(!st.empty() && priority(s[i]) < priority(st.top())){
                    ans+= st.top() ;
                    st.pop() ;
                }
            }
            st.push(s[i]) ;
        }
        i++ ;
    }

    while(!st.empty()){
        ans+= st.top() ;
        st.pop() ;
    }

    reverse(ans.begin(), ans.end()) ;
   
    return ans ;
}

int main(){
    string s = "(p+q)*(m*j-n)" ;
    cout << infixtoPrefix(s) << endl ;
}