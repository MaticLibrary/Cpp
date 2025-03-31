#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Zbior {
    public:
    vector<int> tab;
    size_t size = std::size(tab);

    Zbior(){}

    void DodawanieLiczby() {
        int newelement = 0;
        cout << "Please add a new element: "; cin >> newelement;
        tab.push_back(newelement);
        for (int i = 0; i < tab.size(); i++) {
            cout << tab[i] << ", ";
        }
    }

    void Srednia() {
        double avg = 0;
        for (int i = 0; i < tab.size(); i++) {
            avg += tab[i];
        }
        avg = avg/size;
        cout <<"Srednia wynosi: "<< avg << endl;
    }
    ~Zbior() {}
};

int main() {
    int option;
    Zbior obj1;

    while (true) {
        cout<<"\nSet a option: "; cin>>option;
        if (option == 1) {
            obj1.DodawanieLiczby();
        }else if (option == 2) {
            obj1.Srednia();
        }else {
            break;
        }
    }
    return 0;
}
