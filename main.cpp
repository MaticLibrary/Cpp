#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string zdanie;
    getline(cin, zdanie);
    string cyfry = "";
    string tekst = "";
    for (char ch : zdanie) {
        if (isdigit(ch)) {
            cyfry += ch;
        } else {
            tekst += ch;
        }
    }
    int suma = 0;
    for (char ch : cyfry) {
        suma += ch - '0';
    }
    cout << suma << endl;
    cout << cyfry << endl;
    cout << tekst << endl;
    return 0;
}
