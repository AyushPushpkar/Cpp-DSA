#include<bits/stdc++.h>
using namespace std;

void print17(int n){
    int i,j;
    char ch;
    for(i=0;i<n;i++){
        for(j=n-i-1;j>0;j--){
            cout << " ";
        }
        for(ch='A';ch<='A'+i;ch++){
        cout << ch ;
        }
        for(ch='A'+(i-1);ch>='A';ch--){
        cout << ch ;
        }
        for(j=n-i-1;j>0;j--){
            cout << " ";
        }
        cout << endl;
    }
}
void print18(int n){
    int i,j;
    char ch;
    for(i=0;i<n;i++){
        ch='A'+ (n-i-1);
        for(j=0;j<=i;j++){
            cout << ch << " ";
            ch++;
        }cout << endl;

    }
}    
void print19(int n){
    int i,j;
    int insp = 0;
    for(i=0;i<n;i++){
        for(j=n-i;j>0;j--){
            cout <<  "*";
        }
        for(j=0;j<insp;j++){
            cout<< " ";
        }
        for(j=n-i;j>0;j--){
            cout <<  "*";
        }
        insp+=2;
        cout << endl; 
    }
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            cout <<  "*";
        }
         for(j=0;j<n-i-1;j++){
            cout<< "  ";
        }
        for(j=0;j<=i;j++){
            cout <<  "*";
        }
        cout << endl;
    }    
}
void print20(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            cout << "*";
        }
        for(j=n-i-1;j>0;j--){
            cout << "  ";
        }
        for(j=0;j<=i;j++){
            cout << "*";
        }
        cout << endl; 
    }
    for(i=1;i<n;i++){
        for(j=n-i;j>0;j--){
            cout << "*";
        }
        for(j=1;j<=i;j++){
            cout<< "  ";
        }
        for(j=n-i;j>0;j--){
            cout <<  "*";
        }
        cout << endl;
    }    
}

void print21(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==0 || i==n-1 || j==0 || j==n-1){
                cout << "*" ;
            }
            else
            cout << " " ;
        } cout << endl;  
    }    
}
void print22(int n){
    int i,j;
    for(i=0;i<2*n-1;i++){
        for(j=0;j<2*n-1;j++){
            int top =i ,botm=(2*n-2)-i,left=j,right=(2*n-2)-j;
            cout << (n-min(min(top,botm),min(left,right)));
        }cout << endl;
    }
}

void print23(int n){
    int i,j;
    int insp = 2*n-2;
    for( i=1;i<=2*n-1;i++){
        int stars =i;
        if(i>n) stars = 2*n- i;
        for(j=1;j<=stars;j++){
            cout << "*";
        }
        for(j=1;j<=insp;j++){
            cout << " ";
        }
        for(j=1;j<=stars;j++){
            cout << "*";
        }
        cout << endl;
        if(i<n)insp-=2;
        else insp+=2; 
    }
}

void print24(int n){
    int i,j;
    int insp = 0;
    for( i=1;i<=2*n;i++){
        int stars = n-i+1;
        if(i>n) stars = i-n;
        for(j=1;j<=stars;j++){
            cout << "*";
        }
        for(j=1;j<=insp;j++){
            cout << " ";
        }
        for(j=1;j<=stars;j++){
            cout << "*";
        }
        cout << endl;
        if(i<n)insp+=2;
        if(i>n) insp-=2; 
    }
}

int main(){
    int n;
    cin >> n;
    print24 (n);
    return 0;
}