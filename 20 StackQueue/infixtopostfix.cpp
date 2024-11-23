#include<bits/stdc++.h>
using namespace std ;

int priority(char ch){
    if(ch == '^') return 3 ;
    if(ch == '*' || ch == '/') return 2 ;
    if(ch == '+' || ch == '-') return 1 ;
    return -1 ;
}

string infixtoPostfix(string s){  
    string ans = "" ;      // tc : o(n) + o(n)
    stack<int> st ;        // sc : o(n) + o(n)
    int i = 0 ;
    int n = s.size() ;

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
            while(!st.empty() && priority(s[i]) <= priority(st.top())){
                ans+= st.top() ;
                st.pop() ;
            }
            st.push(s[i]) ;
        }
        i++ ;
    }

    while(!st.empty()){
        ans+= st.top() ;
        st.pop() ;
    }
    return ans ;
}

int main(){
    string s = "(p+q)*(m-n)" ;
    cout << infixtoPostfix(s) << endl ;
}