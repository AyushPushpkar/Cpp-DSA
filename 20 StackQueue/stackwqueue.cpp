#include<bits/stdc++.h>
using namespace std ;

class QueStack {
public:
    queue<int> q;

    void push(int n) {
        int s = q.size();
        q.push(n);

        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int gettop() {
        if (q.empty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return q.front();
    }

    int pop() {
        if (q.empty()) {
            cout << "Stack is empty. Cannot pop." ;
            return -1; 
        }
        int topElement = q.front();
        q.pop();
        return topElement;
    }


    int getsize() {
        return q.size();
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

    return 0;
}
