#include <iostream>
#include <string>

using namespace std;

class ManualCar
{
private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

public:
    ManualCar(string b, string m)
    {
        this->brand = b;
        this->model = m;
        this->isEngineOn = false;
        this->currentSpeed = 0;
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

    void accelerate()
    {
        currentSpeed += 10;
        cout << "Accelerating. Current speed: " << currentSpeed << " km/h" << endl;
    }

    void accelerate(int speedIncrement)
    {
        currentSpeed += speedIncrement;
        cout << "Accelerating. Current speed: " << currentSpeed << " km/h" << endl;
    }

    void brake()
    {
        if (currentSpeed > 0)
        {
            currentSpeed -= 10;
            cout << "Braking. Current speed: " << currentSpeed << " km/h" << endl;
        }
        else
        {
            cout << "Cannot brake. Speed is already zero." << endl;
        }
    }

    virtual ~ManualCar() {}
};

int main()
{
    ManualCar *manualCar = new ManualCar("Toyota", "Corolla");
    manualCar->startEngine();
    manualCar->accelerate();
    manualCar->accelerate(20);
    manualCar->stopEngine();

    delete manualCar;

    return 0;
}