#ifndef Wektor_h
#define Wektor_h

#include <cmath>
#include <string>
#include <sstream>
#include <iostream>
#include <initializer_list>

using namespace std;

class Wektor {
private:
    double* wektor;
    size_t rozmiar;

public:
    Wektor(const double* tablica, size_t rozmiar);
    Wektor(size_t rozmiar = 0, double val = 0.0);
    Wektor(const Wektor& other);
    Wektor(const std::initializer_list<double>& list);
    ~Wektor();

    size_t size() const;
    double norm() const;
    string to_string() const;
    double* begin();
    double* end();
    const double* begin() const;
    const double* end() const;
};

void wypisz_wektor(const Wektor& w);

#endif
