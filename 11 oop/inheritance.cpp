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

    void askForPromotion(){
        if(getCG() > 3) {
            cout << Name << " got promoted !" << endl ;
        }
        else{
            cout << Name << " wasted !" << endl ;
        }
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
};

class core : Student {
public :
    string Subject ;

    void Engineering(){
        cout << Name << " " << Subject << " engineer" << endl ;
    }

    core(string name , int age , int cg ,string subject)
        : Student(name,age,cg) {
            Subject = subject ;
        }
};

int main(){

    Developer d1 = Developer("D@ffy",27 , 6 , "c++") ;
    d1.DSA() ;
    d1.askForPromotion() ;

    core s1 = core("Venom" , 25 ,10 , "Electrical") ;
    s1.Engineering() ;
}