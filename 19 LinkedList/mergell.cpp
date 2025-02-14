#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* mergeSortedLists(Node* L1, Node* L2) {
    // Create a dummy node to simplify the merging process
    Node* dummy = new Node(0);
    Node* tail = dummy; // Tail pointer for the merged list

    // Traverse both L1 and L2 until one of them is fully traversed
    while (L1 != nullptr && L2 != nullptr) {
        if (L1->data <= L2->data) {
            tail->next = L1;   
            L1 = L1->next;    
        } else {
            tail->next = L2;   
            L2 = L2->next;     
        }
        tail = tail->next;     
    }

    // Attach the remaining nodes of L1 or L2
    if (L1 != nullptr) {
        tail->next = L1;  
    } else {
        tail->next = L2;  
    }

    Node* mergedHead = dummy->next;
    delete dummy; // Free the dummy node
    return mergedHead;
}

// Helper function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to append a new node at the end of the list
void append(Node*& head, int data) {
    if (head == nullptr) {
        head = new Node(data);
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new Node(data);
    }
}

int main() {
    Node* L1 = nullptr;
    Node* L2 = nullptr;

    append(L1, 1);
    append(L1, 3);
    append(L1, 5);

    append(L2, 2);
    append(L2, 4);
    append(L2, 6);
    append(L2 , 7);
    append(L2 , 8);

    cout << "List L1: ";
    printList(L1);
    
    cout << "List L2: ";
    printList(L2);

    Node* mergedList = mergeSortedLists(L1, L2);

    cout << "Merged : ";
    printList(mergedList);

    return 0;
}
