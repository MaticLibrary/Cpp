#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

template<typename T>
T srednia(T x, T y, T z) {
    cout<< (x+y+z)/3<<endl;
    return 0;
}

template<typename X, typename Y>
bool Porownanie(X zmiennaX, Y zmiennaY) {
    if (typeid(X) == typeid(Y)) {
        cout<<"Parametry są takie same" << endl;
        return true;
    }else {
        cout<<"Parametry są rozne ";
        return false;
    }
}

template<typename T>
    class Klasa {
    public:
        T tab[10];
        T min;
        T max;

    Klasa(T arr[10]) {
        for (int i = 0; i < 10; ++i) {
            tab[i] = arr[i];
        }
    }
    void minmax(std::vector<T>tab[10]) {
        min = tab[0];
        max = tab[0];
        for (int i = 1; i < 10; ++i) {
            if (tab[i] < min) min = tab[i];
            if (tab[i] > max) max = tab[i];
        }
        cout << "min = " << min << ", max = " << max << endl;
    }
};

int main() {

    return 0;
}
