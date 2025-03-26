#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

struct figura {
    int a,b,suma,iloczyn;
    float srednia;
};

void zad1() {
    int x,y,z;
    cout<<"\nWprowadz wartosc dla x: "; cin>>x;
    cout<<"\nWprowadz wartosc dla y: "; cin>>y;
    cout<<"\nWprowadz wartosc dla z: "; cin>>z;
    cout<<"twoje wartosci to: "<<x<<", "<<y<<", "<<z<<endl;
}

void zad2() {
    string text;
    cout<<"Wprowadz zdanie: ";
    cin.ignore();
    getline(cin, text);
    cout<<"Ilosc znakow: "<<text.length();
}

void zad3() {
    int number = 1;
    int max_value = 1000000;
    int width = log10(max_value) + 1;

    while (number <= max_value) {
        cout.width(width);
        cout.fill(' ');
        cout << number << endl;
        number *= 10;
    }
}

void zad21(int *arr, int length) {
    int temp = 10;
    for (int i = 0; i < length; i++) {
        arr[i] = temp;
        temp += 5;
    }
}

void zad21out(int const *arr, int length) {
    for (int i = 0; i < length; i++) {
        cout<<arr[i]<<" ";
        if (arr[i] % 100 == 0) {
            cout<<endl;
        }
    }
}

void zad3structSet(figura* figura) {
    cout<<"Wprowadz wartosc dla a: "; cin>>(figura -> a);
    cout<<"Wprowadz wartosc dla b: "; cin>>(figura -> b);
}

void zad3structMath(figura* figura) {
    figura ->iloczyn = figura->a * figura->b;
    figura->suma = figura->a + figura->b;
    figura->srednia = (figura->a + figura->b)/2.0;
    cout<<"Iloczyn: "<<figura->iloczyn<<endl;
    cout<<"Suma: "<<figura->suma<<endl;
    cout<<"Srednia: "<<figura->srednia<<endl;
}


int main() {
    cout<<"Zadanie 1: \n";
    zad1();
    cout<<"Zadanie 2: \n";
    zad2();
    cout <<"Zadanie 3: \n";
    zad3();
    cout<<"Zadanie 2.2: \n";
    int static tab[100];
    int length = sizeof(tab)/sizeof(tab[0]);
    zad21(tab, length);
    zad21out(tab, length);
    cout<<"Zadanie 3 Struktura: \n";
    figura f;
    zad3structSet(&f);
    zad3structMath(&f);
    return 0;
}
