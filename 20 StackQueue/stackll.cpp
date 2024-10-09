#include<bits/stdc++.h>
using namespace std ;

struct Node {
    int data;
    struct Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class StackLL{
public:
    struct Node* top = nullptr ;  
    int size =0 ;

    void push(int n){
        Node * newnode = new Node(n) ;
        newnode->next = top  ;
        top = newnode ;
        size = size+1 ;
    }

    int gettop(){
        if(top == nullptr){
            return -1; 
        }
        return top->data ;
    }

    void pop(){
        if (top == nullptr) {  
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top ;
        top = top -> next ;
        delete temp ;
        size = size -1 ; 
    }

    int getsize(){
        return size ; 
    }

};

int main(){

    StackLL s1  ;
    s1.push(5) ;
    s1.pop();
    cout << s1.gettop() << endl;
    s1.push(6);
    s1.push(7);
    s1.push(8);
    cout << s1.getsize() << endl ;
    cout << s1.gettop() << endl ;

}