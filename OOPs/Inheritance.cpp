#include <iostream>
#include <string>

using namespace std;

class Car
{
protected:
    string brand;
    string model;
    bool isEngineOn;

public:
    Car(string b, string m)
    {
        this->brand = b;
        this->model = m;
        this->isEngineOn = false;
    }

    void startEngine()
    {
        isEngineOn = true;
        cout << "Engine started for " << brand << " " << model << endl;
    }

    void stopEngine()
    {
        isEngineOn = false;
        cout << "Engine stopped for " << brand << " " << model << endl;
    }

    virtual ~Car() {}
};

class ManualCar : public Car
{
private:
    int currentGear;

public:
    ManualCar(string b, string m) : Car(b, m)
    {
        this->currentGear = 0;
    }

    void shiftGear()
    {
        if (isEngineOn)
        {
            currentGear++;
            cout << "Shifted to gear " << currentGear << endl;
        }
        else
        {
            cout << "Cannot shift gear. Engine is off." << endl;
        }
    }
};

class ElectricCar : public Car
{
private:
    int batteryPercentage;

public:
    ElectricCar(string b, string m) : Car(b, m)
    {
        this->batteryPercentage = 100;
    }

    void chargeBattery()
    {
        batteryPercentage = 100;
        cout << "Battery charged to 100% for " << brand << " " << model << endl;
    }
};

int main()
{
    ManualCar *manualCar = new ManualCar("Toyota", "Corolla");
    manualCar->startEngine();
    manualCar->shiftGear();
    manualCar->stopEngine();

    delete manualCar;

    cout << "------------------------------" << endl;

    ElectricCar *electricCar = new ElectricCar("Tesla", "Model S");
    electricCar->startEngine();
    electricCar->chargeBattery();
    electricCar->stopEngine();

    delete electricCar;

    return 0;
}