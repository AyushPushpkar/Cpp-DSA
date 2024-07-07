#include<bits/stdc++.h>
using namespace std ;

class Student{
public:
    string Name;
    int Age ;

    void intro(){
        cout << "Name : " << Name << endl ;
        cout << "Age : " << Age << endl ;
    }

    Student(){} // default
    Student(string name , int age){
        Name = name ;
        Age = age ;
    }

};

int main(){

    Student s1  = Student("Ayush",20) ;
    s1.intro() ;

    Student s2 ;
    s2.Name = "Daffy" ;
    s2.Age = 22 ;
    s2.intro() ;

}