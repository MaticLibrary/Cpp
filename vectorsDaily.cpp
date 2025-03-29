#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void wczytaj(vector<float>& wektor) {
    for (int i = 0; i < 4; i++) {
        float liczba;
        cout <<"Podaj liczbe: "; cin >> liczba;
        wektor.push_back(liczba);
    }
}

void wypisz(const vector<float>& wektor, size_t size) {
    for (int i = 0; i < size; i++) {
        cout << wektor[i] << ", ";
    }
}


int main() {
    std::vector<float> wektor;
    wczytaj(wektor);
    size_t size = wektor.size();
    wypisz(wektor,size);
    cout <<"Length: "<<size << "\n";

    cout << "\n";
    cout <<"Proces usuwania dwoch ostatnich liczb"<<endl;
    for (int i = 0; i < 2; i++) {
        wektor.pop_back();
    }
    size = wektor.size();
    wektor[1] = 55.66;
    cout <<"Length: "<<size << "\n";
    for (int i = 0; i < size; i++) {
        cout << wektor[i] << ", ";
    }
    wypisz(wektor,size);

    return 0;
}
