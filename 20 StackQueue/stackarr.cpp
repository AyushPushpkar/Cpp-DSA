#include<bits/stdc++.h>
using namespace std ;

class StackArr{
public:
    int top = -1 ;  
    int st[10] ;   // sc : o(10)     extra space

    void push(int n){   // o(1)
        if(top >= 9){
            cout << "oob" << endl ;
            return ; 
        } 
        top++ ; 
        st[top] = n ; 
    }

    int gettop(){   // o(1)
        if(top == -1){
            return -1; 
        }
        return st[top] ;
    }

    int pop(){   // o(1)
        if(top == -1){
            cout << " empty " << endl;
            return ; 
        }
        int el = st[top];
        top-- ;
        return el ;
    }

    int size(){    // o(1)
        if(top == -1){
            return 0; 
        }
        return top+1 ; 
    }

};

int main(){

    StackArr s1  ;
    s1.push(5) ;
    s1.pop();
    cout << s1.gettop() << endl;
    s1.push(6);
    s1.push(7);
    s1.push(8);
    cout << s1.size() << endl ;
    cout << s1.gettop() << endl ;

}