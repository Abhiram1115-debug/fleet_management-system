#include<bits\stdc++.h>
#include "vehicle.h"

class Van : public Vehicle {
private:
    int cargoVolume;  // in cubic meters

public:
    Van(std::string plate, double consumption, int volume) : Vehicle(plate, consumption), cargoVolume(volume) {}

    void travel(double distance)  {
        std::cout << "Van traveling " << distance << " km.\n";
        Vehicle::travel(distance);
    }

    double calculateFuel(double distance) const  {
        return distance * fuelConsumption;
    }

    void printDetails() const  {
        std::cout << "Van Details:\n";
        Vehicle::printDetails();
        std::cout << "Cargo Volume: " << cargoVolume << " cubic meters\n";
    }
};