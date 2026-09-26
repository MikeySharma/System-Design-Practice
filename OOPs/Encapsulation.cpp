#include <iostream>
#include <string>

using namespace std;

class SportsCar
{
private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

public:
    SportsCar(string b, string m)
    {
        this->brand = b;
        this->model = m;
        this->isEngineOn = false;
        this->currentSpeed = 0;
        this->currentGear = 0;
    }

    // getter and setter

    int getCurrentSpeed()
    {
        return this->currentSpeed;
    }

    void setCurrentSpeed(int speed)
    {
        if (speed >= 0)
        {
            this->currentSpeed = speed;
        }
        else
        {
            cout << "Speed cannot be negative." << endl;
        }
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

    ~SportsCar() {}
};

// Main method
int main()
{
    SportsCar *myCar = new SportsCar("Ferrari", "488 Spider");
    myCar->startEngine();
    myCar->shiftGear();
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();

    // setting arbitrary values to demonstrate encapsulation
    // myCar->currentSpeed = 500;

    // cout << "Current speed after setting arbitrary value: " << myCar->currentSpeed << " km/h" << endl;

    // using getter and setter to access private member
    myCar->setCurrentSpeed(100);
    cout << "Current speed after using setter: " << myCar->getCurrentSpeed() << " km/h" << endl;

    delete myCar;
    return 0;
}