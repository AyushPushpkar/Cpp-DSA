#include<bits/stdc++.h>
using namespace std;

void explainlist(){
    list<int> ls;

    ls.push_back(2);
    ls.emplace_back(4);
    
    ls.push_front(3);
    ls.emplace_front(5);
}

void explainDeque(){
    deque<int>dq;

    dq.pop_front();
    dq.front();
}

void explainStack(){
    //LIFO-last in first order
    stack<int>st;

    st.push(2);
    st.emplace(4);//{4,2}

    cout<< st.top();

    st.pop();

    stack<int>s1,s2;
    s1.swap(s2);
}

void explainQueue(){
    queue<int>q;
    //FIFO-first in first order
    q.push(4);
    q.emplace(1);

    q.back() +=3;
    q.front();

    q.pop();
}

void explainPQ(){
    priority_queue<int>pq;
    //largest at top

    pq.push(2); //logn
    pq.emplace(4);

    pq.top();  //o(1)
    pq.pop();  //logn

    //minimum heap
    priority_queue<int , vector<int> ,greater<int>>pq;

}