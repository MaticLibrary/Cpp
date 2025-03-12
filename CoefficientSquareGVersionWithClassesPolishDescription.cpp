#include <iostream>     //Bibloteka od strumienia cin cout
#include <cmath>        //Bibloteka od matematycznych funkcji

using namespace std;    // Aktywacja cin cout

class RownanieKwadratowe {  //Otwieramy klase rownania kwadratowego
private:                    //Klasa prywatna poniewaz blokuje ona mozliwosc zmiany wartosci przez uzytkownika
    int wsp_a, wsp_b, wsp_c;    // wso --> współczynnik wartosci a b c      trzeba przydzielic prywatne wartosci dla klasy
    double pierwiastek1, pierwiastek2;  // pierwiastek dla x1 x2

public:                                 //czesc publiczna do ktorej ma dostep uzytkownik
    RownanieKwadratowe(int wsp_a, int wsp_b, int wsp_c) : wsp_a(wsp_a), wsp_b(wsp_b), wsp_c(wsp_c), pierwiastek1(0), pierwiastek2(0) {}

    //przyjmujemy wartosci od uzytkownika i rownamy je dla wartosci prywatnych

    int rozwiaz() { //Metoda ta oblicza pierwiastki równania i zwraca liczbę miejsc zerowych.
        if (wsp_a == 0) {
            if (wsp_b == 0) {
                return -2; // Rownanie stałe, brak rozwiazan
            } else {
                pierwiastek1 = -static_cast<double>(wsp_c) / wsp_b;         //    wsp_c jest zmienną typu int, ale dzielenie w C++ między dwoma liczbami całkowitymi (int) wykonuje dzielenie całkowitoliczbowe (czyli zaokrąglone w dół).Aby uzyskać dzielenie zmiennoprzecinkowe, konwertujemy wsp_c na typ double, używając static_cast<double>().static_cast<double>(wsp_c) oznacza: "traktuj wsp_c jako liczbę zmiennoprzecinkową (double), nie jako int".- przed static_cast<double>(wsp_c) oznacza, że wynik będzie przeciwny do wsp_c.wsp_b pozostaje typu int aleponieważ wsp_c został przekonwertowany na double, kompilator automatycznie konwertuje wsp_b nadouble, by wykonać dzieleniezmiennoprzecinkowe.
                return -1; // Rownanie liniowe
            }
        }

        double delta = wsp_b * wsp_b - 4 * wsp_a * wsp_c;   //Przypisujemy dla wartosci delta rownanie aby uproscic pisanie kodu

        if (delta < 0) {                //obliczamy dla delty miejsca zerowe
            return 0;                   // Brak pierwiastkow rzeczywistych
        } else if (delta == 0) {
            pierwiastek1 = -wsp_b / (2.0 * wsp_a);
            return 1; // Jeden pierwiastek
        } else {
            pierwiastek1 = (-wsp_b - sqrt(delta)) / (2.0 * wsp_a);  // x1
            pierwiastek2 = (-wsp_b + sqrt(delta)) / (2.0 * wsp_a);  // x2
            return 2;                               // Dwa pierwiastki
        }
    }

    void wyswietlWyniki(int liczbaPierwiastkow) {           //Metoda wyswietlWyniki Wyświetla na ekranie liczbę oraz wartości pierwiastków.
        switch (liczbaPierwiastkow) {   //LiczbaPierwiastkow metoda rozwiaz
            case 0:
                cout << "Brak miejsc zerowych.\n";
                break;
            case 1:
                cout << "Jedno miejsce zerowe: x = " << pierwiastek1 << endl;
                break;
            case 2:
                cout << "Dwa miejsca zerowe: x1 = " << pierwiastek1 << ", x2 = " << pierwiastek2 << endl;
                break;
            case -1:
                cout << "Rownanie liniowe. Miejsce zerowe: x = " << pierwiastek1 << endl;
                break;
            case -2:
                cout << "Rownanie stałe. Brak rozwiazan.\n";
                break;
            default:
                cout << "Błędna wartosc dla wyjscia...\n";
                break;
        }
    }
};

int main() {
    int wsp_a, wsp_b, wsp_c;

    cout << "\nax^2 + bx + c = 0\n---------------------\n";
    cout << "\nWprowadz wartosc dla a: ";
    cin >> wsp_a;
    cout << "Wprowadz wartosc dla b: ";
    cin >> wsp_b;
    cout << "Wprowadz wartosc dla c: ";
    cin >> wsp_c;

    RownanieKwadratowe rownanie(wsp_a, wsp_b, wsp_c);           //Tworzony jest obiekt rownanie, który przechowuje współczynniki.
    int liczbaPierwiastkow = rownanie.rozwiaz();             //Wywoływana jest metoda rozwiaz(), która zwraca liczbę pierwiastków
    rownanie.wyswietlWyniki(liczbaPierwiastkow);           //Na koniec metoda wyswietlWyniki() wyświetla wyniki obliczeń





    return 0;
}
