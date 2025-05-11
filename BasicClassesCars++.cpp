#include <iostream>
#include <string>
using namespace std;

class Pojazd{
    protected:
           string marka;
           int rok_produkcji;
    public:
        Pojazd(string marka, int rok_produkcji) : marka(marka), rok_produkcji(rok_produkcji){}
        virtual void pokaz_info() = 0;
        virtual ~Pojazd() {};
};
class Samochod : public Pojazd{
    private:
        float pojemnosc_silnika;
    public:
        Samochod(string marka = "BMW", int rok_produkcji = 2010, float pojemnosc_silnika = 2.0) : Pojazd(marka, rok_produkcji) , pojemnosc_silnika(pojemnosc_silnika){} ;
        virtual void pokaz_info() override{
                cout<<"Pojemnosc silnika: "<<pojemnosc_silnika<<endl;
                cout<<"Rok produkcji"<<rok_produkcji<<endl;
                cout<<"Marka"<<marka<<endl;
            }
         virtual ~Samochod() override {};
};
class Motocykl:public Pojazd{
    private:
        bool z_koszem;
    public:
        Motocykl(string marka = "Honda", int rok_produkcji = 2042, bool z_koszem = false) : Pojazd(marka, rok_produkcji), z_koszem(z_koszem){};
        virtual void pokaz_info() override{
                cout<<"Marka: "<<marka<<endl;
                cout<<"Rok produkcji: "<<rok_produkcji<<endl;
                cout<<"Z koszem: "<<z_koszem<<endl;
}

   virtual ~Motocykl() override{};
};


    int main(){
        Pojazd* tablica_pojazdow[3];

        tablica_pojazdow[0] = new Samochod("Audi", 2015, 1.8);
        tablica_pojazdow[1] = new Motocykl("Yamaha", 2020, true);
        tablica_pojazdow[2] = new Samochod("Toyota", 2022, 2.5);

        for (int i = 0; i < 3; ++i) {
            tablica_pojazdow[i]->pokaz_info();
            cout << "---------------------------\n";
        }

        // Zwolnij pamięć
        for (int i = 0; i < 3; ++i) {
            delete tablica_pojazdow[i];
        }

    return 0;
}
