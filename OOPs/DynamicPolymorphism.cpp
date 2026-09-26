#include <iostream>
#include <string>

using namespace std;

class Car
{
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

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

    virtual void accelerate() = 0;
    virtual void brake() = 0;

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

    void accelerate()
    {
        if (isEngineOn)
        {
            currentSpeed += 20;
            cout << "Accelerating. Current speed: " << currentSpeed << " km/h" << endl;
        }
        else
        {
            cout << "Cannot accelerate. Engine is off." << endl;
        }
    }

    void brake()
    {
        if (isEngineOn && currentSpeed > 0)
        {
            currentSpeed -= 20;
            cout << "Braking. Current speed: " << currentSpeed << " km/h" << endl;
        }
        else
        {
            cout << "Cannot brake. Either engine is off or speed is already zero." << endl;
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

    void accelerate()
    {
        if (isEngineOn)
        {
            currentSpeed += 15;
            batteryPercentage -= 5;
            cout << "Accelerating. Current speed: " << currentSpeed << " km/h" << endl;
        }
        else
        {
            cout << "Cannot accelerate. Engine is off." << endl;
        }
    }

    void brake()
    {
        if (isEngineOn && currentSpeed > 0)
        {
            currentSpeed -= 15;
            batteryPercentage -= 2;
            cout << "Braking. Current speed: " << currentSpeed << " km/h" << endl;
        }
        else
        {
            cout << "Cannot brake. Either engine is off or speed is already zero." << endl;
        }
    }
};

int main()
{
    ManualCar *manualCar = new ManualCar("Toyota", "Corolla");
    manualCar->startEngine();
    manualCar->shiftGear();
    manualCar->accelerate();
    manualCar->accelerate();
    manualCar->brake();
    manualCar->brake();
    manualCar->stopEngine();

    delete manualCar;

    cout << "------------------------------" << endl;

    ElectricCar *electricCar = new ElectricCar("Tesla", "Model S");
    electricCar->startEngine();
    electricCar->chargeBattery();
    electricCar->accelerate();
    electricCar->accelerate();
    electricCar->brake();
    electricCar->brake();
    electricCar->stopEngine();

    delete electricCar;

    return 0;
}