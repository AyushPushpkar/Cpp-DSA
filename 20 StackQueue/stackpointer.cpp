#include<bits/stdc++.h>
using namespace std ;

class Stack {
private:
    int* top; // Pointer to the top element
    int* stackBase; // Pointer to the base of the stack
    int capacity; // Total capacity of the stack
    int size; // Current size of the stack

public:
    Stack(int capacity) : capacity(capacity), size(0) {
        stackBase = new int[capacity]; // Dynamically allocate memory for the stack
        top = nullptr;
    }

    void push(int value) {
        if (size == capacity) {
            cout << "Stack overflow. Cannot push " << value << endl;
            return;
        }
        if (size == 0) {
            top = stackBase; // Initialize top to the first element
        } else {
            top++; // Move the top pointer to the next position
        }
        *top = value; // Set the value at the current top
        size++;
        cout << value << " pushed onto the stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow. Cannot pop from an empty stack." << endl;
            return;
        }
        cout << *top << " popped from the stack." << endl;
        if (size == 1) {
            top = nullptr; // Reset top when the stack becomes empty
        } else {
            top--; // Move the top pointer back
        }
        size--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element." << endl;
            return -1;
        }
        return *top;
    }

    bool isEmpty() {
        return size == 0;
    }

    ~Stack() {
        delete[] stackBase; // Free the dynamically allocated memory
        stackBase = nullptr;
        top = nullptr;
    }
};

int main(){

    Stack stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element is: " << stack.peek() << endl;

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop(); 

}