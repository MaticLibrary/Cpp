#include <iostream>
#include <string>
#include <vector>


enum class Scale {K, F, C };

using namespace std;

class Temperature {
private:
    double kelvin;
    static Scale inputScale;
    static Scale outputScale;

public:
    Temperature(double temp) {
        kelvin = toKelvin(temp, inputScale);
    }

    static double toKelvin(double temp, Scale scale) {
        switch (scale) {
            case Scale::C: return temp + 273.15;
            case Scale::F: return (temp + 459.67) * 5.0 / 9.0;
            case Scale::K: return temp;
            default: return temp;
        }
    }

    static double fromKelvin(double kelvin, Scale scale) {
        switch (scale) {
            case Scale::C: return kelvin - 273.15;
            case Scale::F: return kelvin * 9.0 / 5.0 - 459.67;
            case Scale::K: return kelvin;
            default: return kelvin;
        }
    }

    operator double() const {
        return fromKelvin(kelvin, outputScale);
    }

    static void setInputScale(Scale scale) {
        inputScale = scale;
    }

    static void setOutputScale(Scale scale) {
        outputScale = scale;
    }
};

Scale Temperature::inputScale = Scale::C;
Scale Temperature::outputScale = Scale::C;

int main() {
    Temperature::setInputScale(Scale::C);

    vector<Temperature> temperatures;

    double temp;
    cout << "Podaj 5 temperatur w Celsjuszach: " << endl;
    for (int i = 0; i < 5; ++i) {
        cin >> temp;
        temperatures.push_back(temp);
    }

    Temperature::setOutputScale(Scale::F);

    cout << "Temperatury w Farenheicie: " << endl;
    for (const auto& t : temperatures) {
        cout << t << " F" << endl;
    }

    double sumF = 0;
    for (const auto& t : temperatures) {
        sumF += t;
    }
    cout << "Srednia temperatura w Farenheicie: " << sumF / temperatures.size() << " F" << endl;

    Temperature::setOutputScale(Scale::K);

    cout << "Temperatury w Kelwinach: " << endl;
    for (const auto& t : temperatures) {
        cout << t << " K" << endl;
    }

    double sumK = 0;
    for (const auto& t : temperatures) {
        sumK += t;
    }
    cout << "Srednia temperatura w Kelvinach: " << sumK / temperatures.size() << " K" << endl;

    return 0;
}
