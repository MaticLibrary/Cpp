#include <iostream>
#include <string>
using namespace std;

class Animal{
private:
    string animal;
public:
    Animal(string animal) : animal(animal) {} // definicja konstruktora
    virtual void dajGlos() = 0;
};

class Dog : public Animal {
private:
public:
Dog(string animal = "Dog") : Animal(animal) {};
virtual void dajGlos(){
    cout<<"I am Dog\n";
}
};

class Cat : public Animal {
private:
public:
    Cat(string animal = "Cat") : Animal(animal) {};
    virtual void dajGlos(){
        cout<<"I am Cat\n";
}
};

class Cow : public Animal {
private:

public:
    Cow(string animal = "Cow") : Animal(animal) {};
    virtual void dajGlos(){
        cout<<"I am Cow\n";
}
};

    int main(){
    Cow c1;
    c1.dajGlos();

    return 0;
}
