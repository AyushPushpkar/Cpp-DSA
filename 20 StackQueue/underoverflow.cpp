#include<bits/stdc++.h>
using namespace std ;

class Stack {
private:
    int maxSize;
    vector<int> stack;
    
public:
    Stack(int size) : maxSize(size) {}
    
    void push(int value) {
        if (stack.size() >= maxSize) {
            cout << "Stack Overflow! Cannot push " << value << "\n";
            return;
        }
        stack.push_back(value);
        cout << "Pushed: " << value << "\n";
    }
    
    void pop() {
        if (stack.empty()) {
            cout << "Stack Underflow! Cannot pop from an empty stack.\n";
            return;
        }
        int value = stack.back();
        stack.pop_back();
        cout << "Popped: " << value << "\n";
    }
    
    void display() {
        if (stack.empty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack contents: ";
        for (int val : stack) {
            cout << val << " ";
        }
        cout << "\n";
    }
};

int main() {
    int maxSize = 3;  // Limit the stack size to 3 for demonstration
    Stack myStack(maxSize);
    
    // Demonstrate pushing elements
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    
    // Overflow situation
    myStack.push(40);

    myStack.display();
    
    // Demonstrate popping elements
    myStack.pop();
    myStack.pop();
    myStack.pop();

    // Underflow situation
    myStack.pop();

    return 0;
}
