#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int wiek;
public:
    Person(string name, int wiek) : name(name), wiek(wiek) {} //konstrukor
    void output() {
        cout << "Name: " << name << endl;
        cout << "Age: " << wiek << endl;
    }
    void setAge(int nowyWiek) {
        cout << "Set a new Age: "<< endl; cin >> nowyWiek;
        wiek = nowyWiek;
    }
};
int main() {
    Person p1("Amstag",23);
    p1.output();
    return 0;
}
