#include<bits/stdc++.h>
using namespace std;

void toH(int n , char from_rod , char to_rod , char aux_rod ,int &steps){
    if(n==1){
        cout << "Move disk 1 from rod " << from_rod << " to " << to_rod << endl;
        steps++ ;
        return ;  
    }

    toH(n-1 , from_rod , aux_rod , to_rod , steps) ;
    cout << "Move disk " << n << " from rod " << from_rod << " to " << to_rod << endl;
    steps++ ;
    toH(n-1 , aux_rod, to_rod , from_rod , steps) ;
}

int main(){
    int steps = 0 ;
    toH(3 , 'A' , 'B' , 'C' , steps) ;
    cout << "Total steps : " << steps << endl ;
}