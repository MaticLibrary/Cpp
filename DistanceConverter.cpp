 #include <iostream>
using namespace std;

class Jednostka {
public:
    virtual float toSI() const = 0;
    virtual ~Jednostka() {}
};

class Metr : public Jednostka {
    float wartosc;
public:
    Metr(float w) : wartosc(w) {}
    float toSI() const override {
        return wartosc; // metry to SI
    }
};

class Centymetr : public Jednostka {
    float wartosc;
public:
    Centymetr(float w) : wartosc(w) {}
    float toSI() const override {
        return wartosc / 100.0f;
    }
};

class Kilometr : public Jednostka {
    float wartosc;
public:
    Kilometr(float w) : wartosc(w) {}
    float toSI() const override {
        return wartosc * 1000.0f;
    }
};

float convertFromSI(float valueInMeters, int outputUnit) {
    switch (outputUnit) {
        case 1: return valueInMeters * 100.0f;   // do cm
        case 2: return valueInMeters;            // do m
        case 3: return valueInMeters / 1000.0f;  // do km
        default: return valueInMeters;           // domyślnie zostaw w metrach
    }
}

string unitName(int unitOption) {
    switch (unitOption) {
        case 1: return "cm";
        case 2: return "m";
        case 3: return "km";
        default: return "SI";
    }
}

int main() {
    float wartosc;
    int inputUnit, outputUnit;

    cout << "Podaj wartosc: ";
    cin >> wartosc;

    cout << "Jednostka wejsciowa (1 - cm, 2 - m, 3 - km): ";
    cin >> inputUnit;

    cout << "Jednostka wyjsciowa (1 - cm, 2 - m, 3 - km): ";
    cin >> outputUnit;

    Jednostka* jednostka = nullptr;

    switch (inputUnit) {
        case 1:
            jednostka = new Centymetr(wartosc);
            break;
        case 2:
            jednostka = new Metr(wartosc);
            break;
        case 3:
            jednostka = new Kilometr(wartosc);
            break;
        default:
            cout << "Niepoprawna jednostka wejsciowa." << endl;
            return 1;
    }

    float wartoscSI = jednostka->toSI();
    float wynik = convertFromSI(wartoscSI, outputUnit);

    cout << "Wynik: " << wynik << " " << unitName(outputUnit) << endl;

    delete jednostka;
    return 0;
}
