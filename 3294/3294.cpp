
#include <iostream>
#include <string>
using namespace std;

class Driver
{
private:
    string name;
    string surname;
    int age;
    int experience;

public:
    Driver() : name("None"), surname("None"), age(0), experience(0) {}

    Driver(string n, string s, int a, int e)
        : name(n), surname(s), age(a), experience(e) {
    }

    void ShowInfo() const
    {
        cout << "\n--- Driver ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Age: " << age << endl;
        cout << "Driving experience: " << experience << " years" << endl;
    }
};


class Car
{
private:
    string name;
    string kuzov;
    string dvugun;
    int kolesa;
    int fari;

    Driver* driver; 

public:
    Car()
        : name("no name"), kuzov("none"),
        dvugun("none"), kolesa(0), fari(0),
        driver(nullptr) {
    }

    Car(string n, string k, string d, int K, int f)
        : name(n), kuzov(k), dvugun(d),
        kolesa(K), fari(f), driver(nullptr) {
    }

    Car(string n, string k, string d, int K, int f, Driver* dr)
        : name(n), kuzov(k), dvugun(d),
        kolesa(K), fari(f), driver(dr) {
    }

    void AddDriver(Driver* dr)
    {
        driver = dr;
    }

    void Show() const
    {
        cout << "\n--- CAR ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Kuzov: " << kuzov << endl;
        cout << "Dvugun: " << dvugun << endl;
        cout << "Kolesa: " << kolesa << endl;
        cout << "Fari: " << fari << endl;

        if (driver != nullptr)
        {
            driver->ShowInfo();
        }
        else
        {
            cout << "Driver is absent!" << endl;
        }
    }
};


int main()
{
    Driver driver1("Daniil", "Ivanov", 18, 2);
    Driver driver2("Alex", "Petrov", 25, 7);

    Car car1("BMW", "Sedan", "3.0", 4, 2, &driver1);

    car1.Show();
    Car car2("Audi", "Coupe", "2.0", 4, 2);

    car2.AddDriver(&driver2);

    car2.Show();

    Car car3("Toyota", "Universal", "2.5", 4, 2);

    car3.Show();

    return 0;
}


