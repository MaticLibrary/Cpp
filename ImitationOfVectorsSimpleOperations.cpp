#include <iostream>

using namespace std;

void wypiszWektorTablice(const double* tab, int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << tab[i] << " ";
    }
    cout << "]" << endl;
}

double iloczynSkalarnyDwochWektorow(const double* tab1, const double* tab2, int sizeTab) {
    double wynik = 0.0;
    for (int i = 0; i < sizeTab; i++) {
        wynik += tab1[i] * tab2[i];
    }
    return wynik;
}


double* sumaTablic(const double* tab1, const double* tab2, int sizeTab) {
    double* wynik = new double[sizeTab];
    for (int i = 0; i < sizeTab; i++) {
        wynik[i] = tab1[i] + tab2[i];
    }
    return wynik;
}

int main() {
    int sizeTab1 = 5;
    double* tab1v1 = new double[sizeTab1]{1.0, 2.0, 3.0, 4.0, 5.0};
    double* tab1v2 = new double[sizeTab1]{6.0, 7.0, 8.0, 9.0, 10.0};

    int sizeTab2 = 3;
    double tab2v1[] = {0.0, 2.0, 3.0};
    double tab2v2[] = {0.0, 7.0, 0.0};


    double iloczyn1 = iloczynSkalarnyDwochWektorow(tab1v1, tab1v2, sizeTab1);
    double* suma1 = sumaTablic(tab1v1, tab1v2, sizeTab1);

    double iloczyn2 = iloczynSkalarnyDwochWektorow(tab2v1, tab2v2, sizeTab2);
    double* suma2 = sumaTablic(tab2v1, tab2v2, sizeTab2);


    cout << "Wektory pierwszej pary: \n";
    wypiszWektorTablice(tab1v1, sizeTab1);
    wypiszWektorTablice(tab1v2, sizeTab1);
    cout << "Iloczyn skalarny: \n" << iloczyn1;
    cout << "Suma tablic: ";
    wypiszWektorTablice(suma1, sizeTab1);

    cout << "\nWektory drugiej pary: \n";
    wypiszWektorTablice(tab2v1, sizeTab2);
    wypiszWektorTablice(tab2v2, sizeTab2);
    cout << "Iloczyn skalarny: " << iloczyn2;
    cout << " \nSuma tablic: ";
    wypiszWektorTablice(suma2, sizeTab2);

    delete[] tab1v1;
    delete[] tab1v2;
    delete[] suma1;
    delete[] suma2;

    return 0;
}


