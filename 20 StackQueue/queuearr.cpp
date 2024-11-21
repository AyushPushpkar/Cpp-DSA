#include<bits/stdc++.h>
using namespace std ;

class QueueArr{
public:
    int start = -1 ;  
    int end = -1 ;
    int size = 5 ;
    int que[5] ;   // sc : o(5)     extra space
    int cursize = 0 ;

    void push(int n){   // o(1)
        if(cursize == size){
            cout << "Queue already full" << endl ;
        }
        else if(cursize == 0 ){
            start = 0 ;
            end = 0 ;
        }
        else{
            end = (end+1)%size ;
        }
        que[end] = n ;
        cursize++ ;
    }

    int gettop(){   // o(1)
        if(cursize == 0){
            return -1; 
        }
        return que[start] ;
    }

    int pop(){   // o(1)
        int el = que[start] ;
        if(cursize == 0){
            cout << "Queue is empty" << endl ;
        }
        else if(cursize == 1 ){
            start = -1 ;
            end = -1 ;
        }
        else{
            start = (start+1)%size ;
        }
        cursize-- ;
        return el ;
    }

    int getsize(){    // o(1)
        return cursize ;
    }

};

int main(){

    QueueArr q1  ;
    q1.push(5) ;
    cout << q1.pop() << endl;
    cout << q1.gettop() << endl;
    q1.push(6);
    q1.push(7);
    q1.push(8);
    cout << q1.getsize() << endl ;
    cout << q1.gettop() << endl ;

}