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

class QueueLL{
public:
    struct Node* start = nullptr ;
    struct Node* end = nullptr ;  
    int size =0 ;

    void push(int n){
        Node* newnode = new Node(n) ;
        if(start == nullptr){
            start = end = newnode ;
        }
        else{
            end ->next = newnode ;
            end = newnode ;
        }
        size++ ;
    }

    int gettop(){
        if(start == nullptr){
            return -1; 
        }
        return start->data ;
    }

    int pop(){
        if (start == nullptr) {  
            cout << "Stack is empty " ;
            return -1 ;
        }
        Node* temp = start ;
        start = start -> next ;
        if(start == nullptr) end = nullptr ;
        int ans = temp->data ;
        delete temp ;
        size = size -1 ; 
        return ans ;
    }

    int getsize(){
        return size ; 
    }

};

int main(){

    QueueLL q1  ;
    q1.push(5) ;
    cout << q1.pop() << endl;
    cout << q1.gettop() << endl;
    q1.push(6);
    q1.push(7);
    q1.push(8);
    cout << q1.pop() << endl;
    cout << q1.pop() << endl;
    cout << q1.pop() << endl;
    cout << q1.pop() << endl;
    cout << q1.getsize() << endl ;
    cout << q1.gettop() << endl ;

}