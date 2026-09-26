#include <iostream>
#include <string>

using namespace std;

// Real life Car

class Car
{
public:
    virtual void startEngine() = 0;
    virtual void shiftGear() = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopEngine() = 0;
    virtual ~Car() {}
};

class SportsCar : public Car
{
public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    SportsCar(string b, string m)
    {
        this->brand = b;
        this->model = m;
        this->isEngineOn = false;
        this->currentSpeed = 0;
        this->currentGear = 0;
    }

    void startEngine()
    {
        isEngineOn = true;
        cout << "Engine started for " << brand << " " << model << endl;
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
            currentSpeed += 10;
            cout << "Accelarating. Current speed: " << currentSpeed << " km/h" << endl;
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
            currentSpeed -= 10;
            cout << "Braking. Current speed: " << currentSpeed << " km/h" << endl;
        }
        else
        {
            cout << "Cannot brake. Either engine is off or speed is already zero." << endl;
        }
    }

    void stopEngine()
    {
        if (isEngineOn)
        {
            isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0;
            cout << "Engine stopped for " << brand << " " << model << endl;
        }
        else
        {
            cout << "Engine is already off." << endl;
        }
    }
};

// Main method
int main()
{
    Car *myCar = new SportsCar("Ferrari", "488 Spider");
    myCar->startEngine();
    myCar->shiftGear();
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();
    delete myCar;
    return 0;
}