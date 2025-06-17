/*
    Tablica(Tablica&& other) noexcept:tab(other.tab), size(other.size) {
        other.tab = nullptr;
        other.size = 0;
    }
 */

/*
 *
* const std::vector<Książka>& Książki,
        const std::string& wartosc,
        std::string Książka::* pole
        ) {
        for (size_t i = 0;i < Książki.size();++i) {
            if (Książki[i].*pole == wartosc) {
                return static_cast<int>(i);
 *
 */

#include <iostream>
#include <ostream>
#include <vector>
#include <cmath>
#include <random>
using namespace std;
class Temperatura {
    private:
        double temperatura; //kelvin
    public:
    Temperatura(double stopnieC) {
        stopnie = stopnieC + 273.15;
    }
    ~Temperatura() {}
    operator double() const {
        return stopnie - 273.15;
    }
    void wypisz() {
        cout << stopnie << endl;
    }
};

class Transport {
    public:
        void wypisz() {
            cout<<"jestem środkiem transportu "<<endl;
        }
};
class Samochod : public Transport {
    public:
     void wypisz() {
         cout<<"Jestem samochodem";
     }
};
class Statek : public Transport {
    public:
    void wypisz() {
        cout<<"Jestem statkiem";
    }
};
class Amfibia : public Samochod , public Statek {};

void wypisz() {
   Amfibia a;
    a.Samochod::wypisz();
    a.Statek::wypisz();
    a.Samochod::Transport::wypisz();
}

template<typename T>
class stos {
    private:
    std::vector<T> v;
    public:
      void push(const T& element ) {
          v.push_back(element);
      }
};
/**/
class Tablica {
private:
    int *tab;
    int size;
public:

    Tablica(Tablica&& other) noexcept:tab(other.tab), size(other.size) {
        other.tab = nullptr;
        other.size = 0;
    }

    Tablica (const std::initializer_list<int>& lista){
        tab = new int[lista.size()];
        size = lista.size();
        int i=0;
        for(auto el: lista){
            tab[i++] = el;
        }
    }
};

class Klasa : public std::exception {
    private:
        std::string msg;
        int number;
    public:
        Klasa(const std::string& msg, int number) {
            this->msg = msg;
            this->number = number;
        }
    const char* what() const noexcept override{
            return msg.c_str();
        }
    int numberRem() const{
            return number;
        }
};

std::vector<double> funkcja(std::vector<double> v) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] < 0) {
            throw std::out_of_range("Pierwiastek z wartosci ujemnej" + std::to_string(i));
            return i; // ma zwracac pozycje indeksu z bledem
        }else {
            v[i] = std::sqrt(v[i]);
        }
    }
    return v;
}
void serwis(std::vector<double> v) {
    try {
        std::vector<double> wynik =  funkcja(v);
        for (size_t i = 0; i < v.size(); ++i) {
            cout<<wynik[i]<<endl;
        }
    }catch(std::out_of_range& e) {
       cout << e.what();
    }
}

class Klasa1 : public std::exception {
private:
    int number;
    std::string msg;
public:
    Klasa1(int number, std::string msg) : number(number), msg(msg) {}

    const char* what() const noexcept override {
        return msg.c_str();
    }
    int numberRember() const {
        return number;
    }
};

std::vector<double> dzielenieWektorow(std::vector<double> v1, std::vector<double> v2) {
    std::vector<double> wynik;
    if (v1 != v2) {
        cout<<"DzielenieWektorow nie powiodlo sie";
    }else {
        for (size_t i = 0; i < v1.size(); ++i) {
            if (v1[i] != 0 && v2[i] != 0) {
                wynik[i]= v1[i] / v2[i];
            }else {
                throw std::out_of_range("DzielenieWektorow nie powiodlo" + std::to_string(i));
            }
        }
    }
}
void serwis(std::vector<double> v1, std::vector<double> v2) {
        try {
           std::vector<double> wynik =  dzielenieWektorow(v1, v2);
        } catch(std::out_of_range& e) {
            cout << e.what();
        }
}
template<typename K>
class Stos {
    K tab[100];
    int current;
public:
    Stos() : current(-1) {}
    void push(const K& element) {
        tab[++current] = element;
    }
    K pop() {
        return tab[current--];
    }
    bool is_empty() const {
        return current < 0;
    }
};

class Zwierze {
    public:
        void wypisz() {
            cout<<"Jestem zwierzęciem"<<endl;
        }
};
class Ssak : public Zwierze {
    public:
        void wypisz() {
            cout<<"Ssę"<<endl;
        }
};

class Ryba : public Zwierze {
public:
    void wypisz() {
        cout<<"Pływam"<<endl;
    }
};
class Delfin : public Ryba , public Ssak {};
void zwierzak() {
    Delfin delfin;
    delfin.Ryba::wypisz();
    delfin.Ssak::wypisz();
    delfin.Ssak::Zwierze::wypisz();
}
class Książka {
    public:
        std::string autor;
        std::string tytuł;
        std::string wydawca;
    Książka(){}
    int szukaj(
        const std::vector<Książka>& Książki,
        const std::string& wartosc,
        std::string Książka::* pole
        ) {
        for (size_t i = 0;i < Książki.size();++i) {
            if (Książki[i].*pole == wartosc) {
                return static_cast<int>(i);
            }else {
                return -1;
            }
        }
    }
};
