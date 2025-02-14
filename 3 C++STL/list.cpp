#include<bits/stdc++.h>
using namespace std;

void explainList() {
    list<int> ls;

    ls.push_back(2);   // O(1)
    ls.emplace_back(4); // O(1)

    ls.push_front(3);   // O(1)
    ls.emplace_front(5); // O(1)
}

void explainDeque() {
    deque<int> dq;

    dq.push_back(5);  // O(1)
    dq.push_front(10); // O(1)

    dq.pop_front();  // O(1)
    dq.pop_back();   // O(1)

    dq.front();      // O(1)
    dq.back();       // O(1)
}

void explainStack() {
    // LIFO - Last In First Out
    stack<int> st;

    st.push(2);     // O(1)
    st.emplace(4);  // O(1) → Faster than push()

    cout << st.top(); // O(1) → Access top element

    st.pop();        // O(1)

    stack<int> s1, s2;
    s1.swap(s2);     // O(1)
}

void explainQueue() {
    queue<int> q;
    // FIFO - First In First Out

    q.push(4);    // O(1)
    q.emplace(1); // O(1)

    q.back() += 3; // O(1) → Modify last element
    q.front();     // O(1) → Access front element

    q.pop();       // O(1)
}

void explainPQ() {
    // Max Heap (default priority queue) //largest at top
    priority_queue<int> pq;

    pq.push(2);    // O(log n)
    pq.emplace(4); // O(log n)

    pq.top();      // O(1) → Access max element
    pq.pop();      // O(log n)

    // Min Heap (smallest at top)
    priority_queue<int, vector<int>, greater<int>> pq_min;

    pq_min.push(5);    // O(log n)
    pq_min.emplace(1); // O(log n)

    pq_min.top();      // O(1) → Access min element
    pq_min.pop();      // O(log n)
}

