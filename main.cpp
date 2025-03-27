#include "Wektor.h"

int main() {
    Wektor w3 = {1.5, 2.5, 3.5, 4.5, 5.5};
    wypisz_wektor(w3);

    Wektor w4(w3);
    cout << "Wektor w4 (to_string): " << w4.to_string() << endl;

    Wektor w5;
    wypisz_wektor(w5);

    return 0;
}
