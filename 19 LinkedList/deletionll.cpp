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

Node* delStart(Node* head ){
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return nullptr;
    }
    Node* newHead = head->next; // Point to the second node
    delete head; // Delete the old head
    return newHead; // Return the new head
}

void delEnd(Node*& head ){
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    
    // If only one node is present
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;  // Free the last node
    temp->next = nullptr;  // Set the second-last node's next to null
}

void delPosition(Node*& head, int position) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    
    // If position is the first node
    if (position == 1) {
        head = delStart(head);
        return;
    }

    Node* temp = head;

    // Traverse to the node just before the one we want to delete
    for (int i = 1; i < position-1 ; i++) {
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of bounds" << endl;
            return;
        }
        temp = temp->next;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;  // Link previous node to the one after the deleted node
    delete nodeToDelete; // Free the memory
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

    // Node* newStart = delStart(head ) ;
    // delEnd(newStart) ;
    delPosition(head , 3 ) ;
    printLL(head) ;
}