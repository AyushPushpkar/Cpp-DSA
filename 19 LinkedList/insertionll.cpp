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

Node* insertStart(Node* head , int start){
    Node* newNode = new Node(start) ;
    newNode ->next = head ;

    return newNode ;
}

void insertEnd(Node* &head , int End){
    Node* newNode = new Node(End) ;
    if(head == nullptr){
        head = newNode ;
    }
    else{
        Node* temp = head ;
        while(temp->next != nullptr){
            temp = temp ->next ;
        }
        temp -> next = newNode ;
    } 

}

void insertPosition(Node* head , int position , int node){
    Node* newNode = new Node(node) ;
    Node* temp = head ;

    if(position == 1){
        insertStart(head, node) ;
        return ;
    }

    for(int i = 1 ; i<position-1 ;i++){
        if(temp == nullptr){
            cout << " out of bound " << endl ;
            return ;
        }
        else{
            temp = temp->next ;
        }
    }

    newNode -> next = temp->next ;
    temp->next = newNode ;

}

void printLL(Node* head){
    if(head == nullptr) return ;

    cout << head->data << " " ;
    printLL(head->next) ;
}

int main(){

    struct Node* head = new Node(1);

    head->next = new Node(2);
    head->next -> next = new Node(3);
    head->next -> next -> next = new Node(4);
    head->next -> next -> next -> next = new Node(5);
    head->next -> next-> next-> next-> next = new Node(6);

    Node* newStart = insertStart(head , 100) ;
    insertEnd(head , 103) ;
    insertPosition(head , 4 , 102) ;
    printLL(newStart) ;
}