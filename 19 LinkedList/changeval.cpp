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

void updateAtPosition(Node*& head, int position, int newValue) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    // Traverse to the desired position
    for (int i = 1; i < position; i++) {
        temp = temp->next;  // Move to the next node
        if (temp == nullptr) {
            cout << "Position out of range" << endl;
            return;
        }
    }
    
    temp->data = newValue; // Update the value at the specified position
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

    updateAtPosition(head , 4 , 69);  

    cout << "UpdatedLL : ";
    printLL(head);
    cout << endl;
}