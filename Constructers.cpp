#include <iostream>
using namespace std;

class Object{
    private:
        string obj;
        int size;
        string color;
        float price;


    public:
        Object(){
            obj = "BOX";
        }
        // Parametrised Constructer
        Object(string c , int s, float p){
            size = s;
            color = c;
            price = p;
        }
        //Copy Constructer
        Object (Object &o){
            obj = o.obj;
            size = o.size;
            color = o.color;
            price = o.price;
        }
 
    void setdata (string o , string c , int s, float p){
        obj = o;
        size = s;
        color = c;
        price = p;
    }
    //FRIEND FN
    friend void displaydata(Object &o);

    ~Object(){
        cout << "destructor called"<<endl;
    }
};

//Friend Fn 
void displaydata(Object &o){
        cout << "Object : "<< o.obj <<endl;
        cout << "Color : "<< o.color <<endl;
        cout << "Size : "<< o.size <<endl;
        cout << "Price : "<< o.price <<endl<<endl<<endl;
    }

int main(){
    
    Object obj1 , obj2( "Blue", 100 , 49.9);

    displaydata(obj1);
    displaydata(obj2);

    Object obj3(obj2);
    displaydata(obj3);

    
    return 0;

} 