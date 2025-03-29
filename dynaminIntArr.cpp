#include <iostream>
#include <string>
using namespace std;

int main() {
    int temp = 10;
    int length;
    cout << "Please enter the length of the Tab: "; cin >> length;
    int* tab = new int[length];
    for (int i = 0; i < length; i++) {
        tab[i] = temp;
        temp+=5;
    }

    cout << "The Tab is: ";
    for (int i = 0; i < length; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;

    int newLength;
    cout << "Please enter the length of the Tab: "; cin >> newLength;
    int* newTab = new int[newLength];

    int smallest = (newLength > length) ? length : newLength;
    for (int i = 0; i < smallest; i++) {
        newTab[i] = tab[i];
        cout << newTab[i] << " ";
    }

    for (int i = 0; i < newLength; i++) {
        cout << newTab[i] << " ";
    }
    cout << endl;



    delete[] tab;
    return 0;
}
