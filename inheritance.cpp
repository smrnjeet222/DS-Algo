#include <iostream>
using namespace std;

class Animal {
   private:
    int voicepitch;

   public:
    void makeSound() {
        cout << "meooowwwww" << endl;
    }
};

class Dog : public Animal {
   public:
    void makeSound() {
        cout << "BaaahhhhooowhBaahhhhoowh" << endl;
    }
};

int main() {
    Animal Cat;
    Cat.makeSound();

    Dog D1;
    D1.makeSound();

    return 0;
}