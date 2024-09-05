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
    printLL(newStart) ;
}