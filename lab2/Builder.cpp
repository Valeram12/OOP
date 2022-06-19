#include <string>
#include <iostream>

using namespace std;

class Car {
private:
    
    std::string Platform;
    std::string typeOfEngine;
    int SizeOfFuelTank;
    int odometerkm;

public:

    void printCar() {
        cout  << "Platform: " << this->Platform <<"\ntypeOfEngine: "<< this->typeOfEngine<<"\nFuelTankSize: "<< this->SizeOfFuelTank<<"\nodometer: "<< this->odometerkm;
    }

    class Builder {
    public:
     
        std::string body = "";
        std::string engine = "";
        int fuelTankSize = 0;
        bool airCondition = false;
        int odometer = 0;


        Builder* Platform(std::string Platform) {
            this->body = Platform;
            return this;
        }

        Builder* typeOfEngine(std::string typeOfEngine) {
            this->engine = typeOfEngine;
            return this;
        }

        Builder* SizeOfFuelTank(int SizeOfFuelTank) {
            this->fuelTankSize = SizeOfFuelTank;
            return this;
        }


        Builder* odometerkm(int odometerkm) {
            this->odometer = odometerkm;
            return this;
        }

        Car build() {
            return Car(*this);
        }
    };

    Car(Builder builder)
        : Platform(builder.body), typeOfEngine(builder.engine),
        SizeOfFuelTank(builder.fuelTankSize),
        odometerkm(builder.odometer) {}
};

int main() {
    Car automobile = Car::Builder().Platform("Wagon")
        ->typeOfEngine("V8")
        ->SizeOfFuelTank(30)
        ->odometerkm(52421)->build();

    automobile.printCar();

}