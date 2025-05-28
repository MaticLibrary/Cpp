#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

enum RodzajPaliwa {
    PB95 = 1, PB98, ON, ONPLUS, LPG
};

float cena_paliwa(RodzajPaliwa rodzaj) {
    switch (rodzaj) {
        case PB95: return 5.69;
        case PB98: return 6.26;
        case ON: return 5.72;
        case ONPLUS: return 6.00;
        case LPG: return 2.86;
        default: return 0.0;
    }
}

string nazwa_paliwa(RodzajPaliwa rodzaj) {
    switch (rodzaj) {
        case PB95: return "95";
        case PB98: return "98";
        case ON: return "ON";
        case ONPLUS: return "ON+";
        case LPG: return "LPG";
        default: return "Nieznane";
    }
}

class Pojazd {
protected:
    string name;
    float speed;
    float spalanie_na_100km;
    RodzajPaliwa paliwo;
public:
    Pojazd(string n, float s, float spalanie, RodzajPaliwa p)
        : name(n), speed(s), spalanie_na_100km(spalanie), paliwo(p) {}

    virtual float time_of_trace(float distance) = 0;
    virtual float zuzycie_paliwa(float distance) = 0;
    virtual float koszt_paliwa(float distance) {
        return zuzycie_paliwa(distance) * cena_paliwa(paliwo);
    }

    virtual string get_name() { return name; }
    virtual string get_paliwo() { return nazwa_paliwa(paliwo); }
    virtual ~Pojazd() {}
};

class SportCar : public Pojazd {
public:
    SportCar(string n, float s, float spalanie, RodzajPaliwa p)
        : Pojazd(n, s, spalanie, p) {}

    float time_of_trace(float distance) override {
        return distance / (speed + 0.5f * speed);
    }

    float zuzycie_paliwa(float distance) override {
        return spalanie_na_100km * (distance / 100.0f);
    }
};

class Truck : public Pojazd {
    float packed;
public:
    Truck(string n, float s, float spalanie, RodzajPaliwa p, float pck)
        : Pojazd(n, s, spalanie, p), packed(pck) {}

    float time_of_trace(float distance) override {
        return distance / (speed - packed * 0.1f);
    }

    float zuzycie_paliwa(float distance) override {
        float spalanie_z_doladowaniem = spalanie_na_100km + packed * 0.05f;
        return spalanie_z_doladowaniem * (distance / 100.0f);
    }
};

class Motorcykle : public Pojazd {
public:
    Motorcykle(string n, float s, float spalanie, RodzajPaliwa p)
        : Pojazd(n, s, spalanie, p) {}

    float time_of_trace(float distance) override {
        return distance / (speed + 5.0f);
    }

    float zuzycie_paliwa(float distance) override {
        return spalanie_na_100km * (distance / 100.0f);
    }
};

int main() {
    const float DISTANCE = 1000.0f;
    vector<Pojazd*> pojazdy;

    int ile;
    cout << "Ile pojazdow chcesz dodac? ";
    cin >> ile;

    for (int i = 0; i < ile; i++) {
        cout << "\nDodajesz pojazd #" << i + 1 << endl;
        cout << "Wybierz typ pojazdu:\n1. SportCar\n2. Truck\n3. Motorcykle\n";
        int wybor;
        cin >> wybor;

        string nazwa;
        float predkosc, spalanie;
        cout << "Podaj nazwe pojazdu: ";
        cin.ignore();
        getline(cin, nazwa);
        cout << "Podaj predkosc (km/h): ";
        cin >> predkosc;
        cout << "Podaj spalanie na 100 km (l): ";
        cin >> spalanie;

        cout << "Wybierz rodzaj paliwa:\n";
        cout << "1. 95 (5.69 zl)\n2. 98 (6.26 zl)\n3. ON (5.72 zl)\n4. ON+ (6.00 zl)\n5. LPG (2.86 zl)\n";
        int p;
        cin >> p;
        RodzajPaliwa rodzaj = static_cast<RodzajPaliwa>(p);

        if (wybor == 1) {
            pojazdy.push_back(new SportCar(nazwa, predkosc, spalanie, rodzaj));
        }
        else if (wybor == 2) {
            float ladunek;
            cout << "Podaj wage ladunku (kg): ";
            cin >> ladunek;
            pojazdy.push_back(new Truck(nazwa, predkosc, spalanie, rodzaj, ladunek));
        }
        else if (wybor == 3) {
            pojazdy.push_back(new Motorcykle(nazwa, predkosc, spalanie, rodzaj));
        }
        else {
            cout << "Nieznany typ pojazdu. Pomijam.\n";
        }
    }

    struct Wynik {
        string nazwa;
        float czas;
        float paliwo;
        float koszt;
        string paliwo_typ;
    };

    vector<Wynik> wyniki;
    for (auto p : pojazdy) {
        wyniki.push_back({
            p->get_name(),
            p->time_of_trace(DISTANCE),
            p->zuzycie_paliwa(DISTANCE),
            p->koszt_paliwa(DISTANCE),
            p->get_paliwo()
        });
    }

    sort(wyniki.begin(), wyniki.end(), [](Wynik a, Wynik b) {
        return a.czas < b.czas;
    });

    cout << fixed << setprecision(2);
    cout << "\nWyniki  na dystansie " << DISTANCE << " km:\n";
    cout << "---------------------------------------------------------\n";
    int miejsce = 1;
    for (auto& w : wyniki) {
        cout << miejsce++ << ". " << w.nazwa
             << " | czas: " << w.czas << " h"
             << " | paliwo: " << w.paliwo << " l"
             << " | paliwo: " << w.paliwo_typ
             << " | koszt: " << w.koszt << " zl\n";
    }

    for (auto p : pojazdy)
        delete p;

    return 0;
}
