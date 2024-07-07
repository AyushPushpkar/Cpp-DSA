#include<bits/stdc++.h>
using namespace std ;

class Student{
private:
    string Name;
    int Age ;

public:

    void setName(string name){
        Name = name ;
    }
    string getName(){
        return Name ;
    }
    void setAge(int age){
        if(age <= 30)
        Age = age ;
    }
    int getAge(){
        return Age ;
    }

    Student(){}
    Student(string name , int age){
        Name = name ;
        Age = age ;
    }

    void intro(){
        cout << "Name : " << getName() << endl ;
        cout << "Age : " << getAge() << endl ;
    }

};

int main(){

    Student s1  = Student("Ayush",20) ;
    s1.intro() ;

    s1.setAge(32) ;  // only if check true 

    Student s2 ;
    s2.setAge(22) ;
    s2.setName("D@ffy") ;
    s2.intro() ;

}