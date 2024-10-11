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

void revLL(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* tempnext = nullptr;
    
    while (current != nullptr) {
        tempnext = current->next;  // Store next node
        current->next = prev;  // Reverse current node's pointer
        prev = current;        // Move prev and current one step forward
        current = tempnext;
    }
    head = prev;  // Update head to the new front of the list
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

    cout << "OriginalLL : ";
    printLL(head);
    cout << endl;

    revLL(head);  

    cout << "ReversedLL : ";
    printLL(head);
    cout << endl;
}