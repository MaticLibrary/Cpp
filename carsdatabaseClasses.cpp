#include <iostream>
#include <vector>

using namespace std;

class Cars {
    struct Car {
        string name, model, year, color, score, power, price;
    };
    vector<Car> carsvector;

public:
    void setCar() {
        Car newCar;
        cout << "Enter name (e.g., W140): "<<endl;
        cin >> newCar.name;
        cout << "Enter model (e.g., Mercedes Benz): "<<endl;
        cin >> newCar.model;
        cout << "Enter year (e.g., 1995): "<<endl;
        cin >> newCar.year;
        cout << "Enter color (e.g., Black): "<<endl;
        cin >> newCar.color;
        cout << "Enter mileage (e.g., 105432): "<<endl;
        cin >> newCar.score;
        cout << "Enter power (e.g., 172 HP): "<<endl;
        cin >> newCar.power;
        cout << "Enter price (e.g., 50000): "<<endl;
        cin >> newCar.price;

        carsvector.push_back(newCar);
        cout << "Car added successfully\n";
    }

    void displaylistOfCars() {
        if (carsvector.empty()) {
            cout << "list is empty\n";
            return;
        }

        cout << "List of Cars:\n";
        for (size_t i = 0; i < carsvector.size(); i++) {
            cout << i + 1 << ". " << carsvector[i].model << " -  |  - " << carsvector[i].name<< " (" << carsvector[i].year << ") - " << carsvector[i].color<< ", Power: " << carsvector[i].power << " HP, Price: " << carsvector[i].price << " PLN\n";
        }
    }

    void deleteCar() {
        if (carsvector.empty()) {
            cout << "No cars to delete.\n";
            return;
        }

        int index;
        cout << "Enter the number of the car to delete: ";
        cin >> index;

        if (index < 1 || index > carsvector.size()) {
            cout << "Invalid number.\n";
            return;
        }

        carsvector.erase(carsvector.begin() + (index - 1));
        cout << "Car has been deleted.\n";
    }
};

int main() {
    Cars cars;
    int option;

    while (true) {
        cout << "\n Welcome to Auto Service \n";
        cout << "---------------------------\n";
        cout << "1. Show all cars\n";
        cout << "2. Add a car\n";
        cout << "3. Delete a car\n";
        cout << "4. Exit\n";
        cout << "Select an option: ";
        cin >> option;

        switch (option) {
            case 1:
                cars.displaylistOfCars();
                break;
            case 2:
                cars.setCar();
                break;
            case 3:
                cars.deleteCar();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid option! Try again.\n";
        }
    }

}
