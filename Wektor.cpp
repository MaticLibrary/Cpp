#include "Wektor.h"

Wektor::Wektor(const double* tablica, size_t rozmiar) {
    this->rozmiar = rozmiar;
    wektor = new double[rozmiar];
    for (size_t i = 0; i < rozmiar; ++i) {
        wektor[i] = tablica[i];
    }
}

Wektor::Wektor(size_t rozmiar, double val) {
    this->rozmiar = rozmiar;
    if (rozmiar > 0) {
        wektor = new double[rozmiar];
        for (size_t i = 0; i < rozmiar; ++i) {
            wektor[i] = val;
        }
    } else {
        wektor = nullptr;
    }
}

Wektor::Wektor(const Wektor& other) : Wektor(other.wektor, other.rozmiar) {}


Wektor::Wektor(const std::initializer_list<double>& list) {
    rozmiar = list.size();
    wektor = new double[rozmiar];
    size_t i = 0;
    for (auto elem : list) {
        wektor[i++] = elem;
    }
}

Wektor::~Wektor() {
    delete[] wektor;
}

size_t Wektor::size() const {
    return rozmiar;
}


double Wektor::norm() const {
    double suma_kwadratow = 0;
    for (size_t i = 0; i < rozmiar; ++i) {
        suma_kwadratow += wektor[i] * wektor[i];
    }
    return sqrt(suma_kwadratow);
}

string Wektor::to_string() const {
    ostringstream oss;
    for (size_t i = 0; i < rozmiar; ++i) {
        oss << wektor[i] << " ";
    }
    return oss.str();
}

double* Wektor::begin() {
    return wektor;
}

double* Wektor::end() {
    return wektor + rozmiar;
}

const double* Wektor::begin() const {
    return wektor;
}

const double* Wektor::end() const {
    return wektor + rozmiar;
}

void wypisz_wektor(const Wektor& w) {
    for (auto elem : w) {
        cout << elem << " ";
    }
    cout << endl;
}
