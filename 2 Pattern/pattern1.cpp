#include<bits/stdc++.h>
using namespace std;

void print2(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            cout << "* ";
        }cout << endl;
    }
}
void print3(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            cout << j+1 << " ";
        }cout << endl;
    }
}
void print4(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            cout << i+1 << " ";
        }cout << endl;
    }
}
void print5(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=n-i;j>0;j--){
            cout << "* ";
        }cout << endl;
    }
}
void print6(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n-i;j++){
            cout << j+1 << " ";
        }cout << endl;
    }
}
void print7(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=n-i-1;j>0;j--){
            cout << " ";
        }
        for(j=0;j<2*i+1;j++){
            cout << "*"   ;
        } 
        for(j=n-i-1;j>0;j--){
            cout << " ";
        }cout << endl ;
    }
}
void print8(int n){
    int i,j;
    for(i=n-1;i>=0;i--){
        for(j=n-i-1;j>0;j--){
            cout << " ";
        }
        for(j=0;j<2*i+1;j++){
            cout << "*"   ;
        } 
        for(j=n-i-1;j>0;j--){
            cout << " ";
        }cout << endl ;
    }
}
void print9(int n){
    int i,j,k;
    for(i=0;i<n;i++){
        for(j=n-i-1;j>0;j--){
            cout << " ";
        }
        for(j=0;j<2*i+1;j++){
            cout << "*"   ;
        } 
        for(j=n-i-1;j>0;j--){
            cout << " ";
        }cout << endl ;
    }
    for(i=n-1;i>=0;i--){
        for(j=n-i-1;j>0;j--){
            cout << " ";
        }
        for(j=0;j<2*i+1;j++){
            cout << "*"   ;
        } 
        for(j=n-i-1;j>0;j--){
            cout << " ";
        }cout << endl ;
    }
}
void print10(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            cout << "*"   ;
        }cout << endl ;
    }
    for(i=n-2;i>=0;i--){
        for(j=0;j<=i;j++){
            cout << "*"   ;
        }cout << endl ;
    }
}
void print11(int n){
    int i,j,start;
    for(i=1;i<=n;i++){
        if(i%2==0)
        start=0;
        else
        start=1;
        for(j=1;j<=i;j++){
            cout << start << " ";
            start =1-start;
        }
        cout << endl;
    }
}
void print12(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            cout << j+1;
        }
         for(j=0;j<2*(n-i-1);j++){
            cout << " ";
        } 
        for(j=i;j>=0;j--){
            cout << j+1;
        }
        cout << endl;
    }
}
void print13(int n){
    int i,j,num=1;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
        cout << num << " " ;
        num+=1;
        }
        cout << endl;
    }
}
void print14(int n){
    int i;
    char ch;
    for(i=0;i<n;i++){
        for(ch='A';ch<='A'+i;ch++){
        cout << ch ;
        }
        cout << endl;
    }
}
void print15(int n){
    int i;
    char ch;
    for(i=n-1;i>=0;i--){
        for(ch='A';ch<='A'+i;ch++){
        cout << ch ;
        }
        cout << endl;
    }
}
void print16(int n){
    int i,j;
    char ch;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
        ch='A'+i;    
        cout << ch ;
        }
        cout << endl;
    }
}

void printt(int n){
    int i,j;
    for(i=0;i<2*n-1;i++){
        int stars = i+1;
        if(i>n-1) stars = 2*n-i-1;
        for(j=0;j<stars;j++){
            cout << "*"   ;
        }cout << endl ;
    }
}

int main(){
    int n;
    cin >> n;
    print3(n);
    return 0;
}