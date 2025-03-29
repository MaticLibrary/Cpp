#include <iostream>
#include <string>

using namespace std;

void ustawiaj(int& liczba, string& zdanie, int tablica[12]) {

    liczba = 42;
    zdanie = "To jest przykladowe zdanie.";
    for (int i = 0; i < 12; ++i) {
        tablica[i] = i * 2;
    }
}

void drukuj(const int liczba, const string& zdanie, const int tablica[12]) {

    cout << "Liczba: " << liczba << endl;
    cout << "Zdanie: " << zdanie << endl;
    cout << "Tablica: ";
    for (int i = 0; i < 12; ++i) {
        cout << tablica[i] << " ";
    }
    cout << endl;
}

int main() {

    int liczba;
    string zdanie;
    int tablica[12];

    ustawiaj(liczba, zdanie, tablica);

    drukuj(liczba, zdanie, tablica);

    return 0;
}
