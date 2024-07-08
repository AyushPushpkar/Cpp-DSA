#include<bits/stdc++.h>
using namespace std ;

class Student {
private:
    int Age ;
    int CG ;

protected:
    string Name;

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
    void setCG(int cg){
        CG = cg ;
    }
    int getCG(){
        return CG ;
    }

    Student(){}
    Student(string name , int age , int cg){
        Name = name ;
        Age = age ;
        CG = cg ;
    }

    virtual void assignment(){
        cout << Name << " your assignment is due !" << endl; 
    }
    virtual void pyq(){
        cout << Name << " is practising pyq" << endl; 
    }

};

class Developer : public Student {  // private by default
public :
    string ProgrammingLanguage ;

    Developer(string name , int age , int cg ,string pl)
        : Student(name,age,cg){
            ProgrammingLanguage = pl ;
        }

    void DSA(){
        cout << getName() << " learning DSA using " << ProgrammingLanguage << endl ;
    }

    void assignment(){
        cout << Name << " is working on " << ProgrammingLanguage << " based project" << endl; 
    }
};

class core : public Student {
public :
    string Subject ;

    void Engineering(){
        cout << Name << " " << Subject << " engineer" << endl ;
    }

    core(string name , int age , int cg ,string subject)
        : Student(name,age,cg) {
            Subject = subject ;
        }

    void assignment(){
        cout << Name << " is working on " << Subject << " based project " << endl; 
    }
};

int main(){

    //parent class ref is used to refer to a child class object

    Developer d1 = Developer("D@ffy",27 , 6 , "c++") ;

    core s1 = core("Venom" , 25 ,10 , "Electrical") ;
    s1.assignment() ;

    Student* p1 = &d1 ;
    Student* p2 = &s1 ;

    p1->assignment();
    p2->pyq() ;
}