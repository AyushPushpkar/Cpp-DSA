#include<bits/stdc++.h>
using namespace std ;

class QueStack {
public:
    stack<int> s1 , s2;  // sc : o(2s)

    void push(int n) {  // o(2n)
        while(s1.size()){
            s2.push(s1.top());
            s1.pop() ;
        }

        s1.push(n) ;

        while(s2.size()){
            s1.push(s2.top());
            s2.pop() ;
        }
    }

    int gettop() {
        if (s1.empty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return s1.top();
    }

    int pop() {
        if (s1.empty()) {
            cout << "Queue is empty. Cannot pop." ;
            return -1; 
        }
        int topElement = s1.top();
        s1.pop();
        return topElement;
    }


    int getsize() {
        return s1.size();
    }
};

class QueStack2 {
public:
    stack<int> s1 , s2;  // sc : o(2s)

    void push(int n) {  // o(1)
        s1.push(n);
    }

    int gettop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.empty() ? -1 : s2.top();
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) {
            return -1; 
        }
        int popel = s2.top();
        s2.pop();
        return popel;
    }


    int getsize() {
        return s1.size() + s2.size();
    }
};

int main() {
    QueStack q1;

    q1.push(5);
    cout << "Popped element: " << q1.pop() << endl;

    cout << "Size after popping: " << q1.getsize() << endl;

    q1.push(6);
    q1.push(7);
    q1.push(8);

    cout << "Top element: " << q1.gettop() << endl;

    cout << "Popped element: " << q1.pop() << endl;
    cout << "Top element after popping: " << q1.gettop() << endl;

    cout << "Popped element: " << q1.pop() << endl;
    cout << "Popped element: " << q1.pop() << endl;

    cout << "Popped element: " << q1.pop() << endl;

    cout << "Size: " << q1.getsize() << endl;
    cout << "Top element: " << q1.gettop() << endl;

    cout << "\n\n" << endl;

    QueStack2 q2;

    q2.push(5);
    cout << "Popped element: " << q2.pop() << endl;

    cout << "Size after popping: " << q2.getsize() << endl;

    q2.push(6);
    q2.push(7);
    q2.push(8);

    cout << "Top element: " << q2.gettop() << endl;

    cout << "Popped element: " << q2.pop() << endl;
    cout << "Top element after popping: " << q1.gettop() << endl;

    cout << "Popped element: " << q2.pop() << endl;
    cout << "Popped element: " << q2.pop() << endl;

    cout << "Popped element: " << q2.pop() << endl;

    cout << "Size: " << q2.getsize() << endl;
    cout << "Top element: " << q2.gettop() << endl;

    return 0;
}
