#include "vehicle.h"
class Truck : public Vehicle {
private:
    double loadCapacity;  // in tons

public:
    Truck(std::string plate, double consumption, double capacity) : Vehicle(plate, consumption), loadCapacity(capacity) {}

    void travel(double distance)  {
        std::cout << "Truck traveling " << distance << " km.\n";
        Vehicle::travel(distance);
    }

    double calculateFuel(double distance) const  {
        return distance * fuelConsumption;
    }

    void printDetails() const  {
        std::cout << "Truck Details:\n";
        Vehicle::printDetails();
        std::cout << "Load Capacity: " << loadCapacity << " tons\n";
    }
};
