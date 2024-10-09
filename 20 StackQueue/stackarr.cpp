#include<bits/stdc++.h>
using namespace std ;

class StackArr{
public:
    int top = -1 ;  
    int st[10] ;

    void push(int n){
        if(top >= 9){
            cout << "oob" << endl ;
            return ; 
        } 
        top++ ; 
        st[top] = n ; 
    }

    int gettop(){
        if(top == -1){
            return -1; 
        }
        return st[top] ;
    }

    void pop(){
        if(top == -1){
            cout << " empty " << endl;
            return ; 
        }
        top-- ;
    }

    int size(){
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