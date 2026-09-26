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
        this->currentSpeed = 0;
    }

    void startEngine()
    {
        this->isEngineOn = true;
        cout << "Engine started for " << brand << " " << model << endl;
    };
    void stopEngine()
    {
        this->isEngineOn = false;
        cout << "Engine stopped for " << brand << " " << model << endl;
    };
    void brake()
    {
        this->currentSpeed -= 10;
        cout << "Braking. Current speed: " << currentSpeed << " km/h" << endl;
    };
    virtual void accelerate() = 0;
    virtual void accelerate(int speedIncrement) = 0;

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
            currentSpeed += 10;
            cout << "Accelerating. Current speed: " << currentSpeed << " km/h" << endl;
        }
        else
        {
            cout << "Cannot accelerate. Engine is off." << endl;
        }
    }

    void accelerate(int speedIncrement)
    {
        if (isEngineOn)
        {
            currentSpeed += speedIncrement;
            cout << "Accelerating. Current speed: " << currentSpeed << " km/h" << endl;
        }
        else
        {
            cout << "Cannot accelerate. Engine is off." << endl;
        }
    }
};

int main()
{
    ManualCar *manualCar = new ManualCar("Toyota", "Corolla");
    manualCar->startEngine();
    manualCar->shiftGear();
    manualCar->accelerate();
    manualCar->accelerate(20);
    manualCar->brake();
    manualCar->stopEngine();

    // clean up
    delete manualCar;
}