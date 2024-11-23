#include<bits/stdc++.h>
using namespace std ;

class StackArr{
public:
    int top = -1 ;  
    int st[10] ;  

    void push(int n){  
        top++ ; 
        st[top] = n ; 
    }

    int gettop(){   
        if(top == -1){
            return -1; 
        }
        return st[top] ;
    }

    int pop(){  
        int el = st[top];
        top-- ;
        return el ;
    }

    bool isPalindrome(string str){
        int len = str.size() ;

        for(int i =0 ; i< len/2 ; i++){
            push(str[i]) ;
        }
        for(int i = (len+1)/2 ; i < len ; i++){
            if(str[i] != gettop())return 0 ;
            pop() ;
        }

        return 1 ; 
    }

};

int main(){

    string str = "abcdcba" ;

    StackArr s1  ;
    cout << s1.isPalindrome(str) ;

}