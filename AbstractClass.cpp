#include <iostream>
using namespace std;

class BaseClass1{
    public:

        virtual void performFn() = 0;  //Pure Virtual Fn
        
        void show(){
            cout << "show base1 class fn"<<endl;
        }
        virtual void print(){
            cout<< "Print base1 class fn"<<endl; 
        } 
        void MInh(){
            cout<<"Mul Inheritance from base class 1"<<endl;
        }

};
class BaseClass2{
    public:

        virtual void performFn() = 0;  //Pure Virtual Fn
        
        void show(){
            cout << "show base2 class fn"<<endl;
        }
        virtual void print(){
            cout<< "Print base2 class fn"<<endl; 
        } 
        void MInh(){
            cout<<"Mul Inheritance from base class 2"<<endl;
        }

};
// Multiple Inheritance 

class DerivedClass: public BaseClass1 , public BaseClass2{
    public:
        void performFn(){
            cout << "Fn Performed"<< endl;
        }
        void show(){
            cout << "Show Derived class fn"<<endl;
        }
        void print(){
            cout<< "Print Derived class fn"<<endl;
        }
        void MInh(){
            //cout<<"Mul Inheritance from derives class "<<endl;

            BaseClass1::MInh(); //this will call fn in 1 class 
        }  

};

int main(){
    BaseClass1 *baseptr1;
    DerivedClass DerivedObj;

    baseptr1 = &DerivedObj;

    baseptr1->show();
    baseptr1->print();
    DerivedObj.MInh();


    return 0 ;
}