#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Function to move all even-positioned nodes to the end
void rearrange(Node* &head) {
    if (!head || !head->next) return;

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even; // To connect even nodes at the end of odd nodes later
    
    // Traverse the list, separating odd and even positioned nodes
    while (even && even->next) {
        odd->next = odd->next->next;  // Connect odd nodes
        even->next = even->next->next;  // Connect even nodes
        
        odd = odd->next;
        even = even->next;
    }

    // Connect the last odd node to the first even node
    odd->next = evenHead;
}

void printList(Node* head) {
    while (head) {
        cout << static_cast<char>(head->data) << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to add a new node to the end of the list
void append(Node* &head, char data) {
    if (!head) {
        head = new Node(data);
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new Node(data);
    }
}

int main() {
    Node* head = nullptr;

    append(head, 'a');
    append(head, '1');
    append(head, 'b');
    append(head, '2');
    append(head, 'c');
    append(head, '3');
    append(head, 'd');
    append(head, '4');

    cout << "Original list: ";
    printList(head);

    rearrange(head);

    cout << "Rearranged list: ";
    printList(head);

    return 0;
}
