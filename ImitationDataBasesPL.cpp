#include <iostream>
using namespace std;

struct wpis {
    char Imie[20];
    char Nazwisko[20];
    long NumerTelefonu;
};

struct Baza {
    int liczbarekordow;
    int maksymalnyrozmiar;
    wpis* wpisy;
};

void KopiujTekst(char* cel, const char* zrodlo) {
    int i = 0;
    while (zrodlo[i] != '\0' && i < 19) {
        cel[i] = zrodlo[i];
        i++;
    }
    cel[i] = '\0';
}

int DodajWpis(Baza* baza, const wpis* nowyWpis) {
    if (baza->liczbarekordow >= baza->maksymalnyrozmiar) {
        int nowyRozmiar = baza->maksymalnyrozmiar + 10;
        wpis* nowaTablica = new wpis[nowyRozmiar];
        if (!nowaTablica) {
            cout << "Błąd alokacji pamięci!" << endl;
            return -1; // Nieudana alokacja pamięci
        }
        for (int i = 0; i < baza->liczbarekordow; i++) {
            nowaTablica[i] = baza->wpisy[i];
        }

        delete[] baza->wpisy;
        baza->wpisy = nowaTablica;
        baza->maksymalnyrozmiar = nowyRozmiar;
    }

    KopiujTekst(baza->wpisy[baza->liczbarekordow].Imie, nowyWpis->Imie);
    KopiujTekst(baza->wpisy[baza->liczbarekordow].Nazwisko, nowyWpis->Nazwisko);
    baza->wpisy[baza->liczbarekordow].NumerTelefonu = nowyWpis->NumerTelefonu;

    baza->liczbarekordow++;
    return 0;
}

void UsunWpis(Baza* baza, int indeks) {
    if (indeks < 0 || indeks >= baza->liczbarekordow) {
        cout << "Niepoprawny indeks!" << endl;
        return;
    }

    for (int i = indeks; i < baza->liczbarekordow - 1; i++) {
        baza->wpisy[i] = baza->wpisy[i + 1];
    }

    baza->liczbarekordow--;
}

void WyswietlanieZawartosciKsiazki(const Baza* baza) {
    if (baza->liczbarekordow == 0) {
        cout << "Baza jest pusta!" << endl;
        return;
    }

    cout << "Baza danych: " << endl;
    for (int i = 0; i < baza->liczbarekordow; i++) {
        cout << i << ". Imię: " << baza->wpisy[i].Imie
             << ", Nazwisko: " << baza->wpisy[i].Nazwisko
             << ", Numer telefonu: " << baza->wpisy[i].NumerTelefonu << endl;
    }
}


void ZwolnijBaze(Baza* baza) {
    delete[] baza->wpisy;
    baza->wpisy = nullptr;
    baza->liczbarekordow = 0;
    baza->maksymalnyrozmiar = 0;
}

int main() {
    Baza baza;
    baza.liczbarekordow = 0;
    baza.maksymalnyrozmiar = 10;
    baza.wpisy = new wpis[baza.maksymalnyrozmiar];

    int opcja;
    do {
        cout << "\nWybierz opcję:\n"
             << "1. Dodaj wpis\n"
             << "2. Usun wpis\n"
             << "3. Wyswietl ksiazke\n"
             << "4. Zakoncz\n"
             << "Opcja: ";
        cin >> opcja;

        switch (opcja) {
            case 1: {
                wpis nowy;
                cout << "Podaj imie: ";
                cin >> nowy.Imie;
                cout << "Podaj nazwisko: ";
                cin >> nowy.Nazwisko;
                cout << "Podaj numer telefonu: ";
                cin >> nowy.NumerTelefonu;

                if (DodajWpis(&baza, &nowy) == -1) {
                    cout << "Nie udało się dodać wpisu!" << endl;
                }
                break;
            }
            case 2: {
                int indeks;
                cout << "Podaj indeks do usuniecia: ";
                cin >> indeks;
                UsunWpis(&baza, indeks);
                break;
            }
            case 3:
                WyswietlanieZawartosciKsiazki(&baza);
                break;
            case 4:
                cout << "Zamykanie programu..." << endl;
                break;
            default:
                cout << "Niepoprawna opcja!" << endl;
                break;
        }
    } while (opcja != 4);


    ZwolnijBaze(&baza);

    return 0;
}
