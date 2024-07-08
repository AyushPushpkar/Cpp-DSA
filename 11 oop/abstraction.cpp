#include<bits/stdc++.h>
using namespace std ;

class AbstractStudent{

    virtual void askForPromotion() = 0; //obligatory 
};

class Student : AbstractStudent{
private:
    string Name;
    int Age ;
    int CG ;

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

    void intro(){
        cout << "Name : " << getName() << endl ;
        cout << "Age : " << getAge() << endl ;
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

int main(){

    Student s1  = Student("Ayush",20 , 8) ;
    s1.intro() ;
    s1.askForPromotion() ;

    Student s2 ;
    s2.setAge(22) ;
    s2.setName("D@ffy") ;
    s2.setCG(3) ;
    s2.intro() ;

    s2.askForPromotion() ;

}