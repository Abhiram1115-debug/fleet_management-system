#ifndef VEHICLE_H
#define VEHICLE_H
#include <bits/stdc++.h>

class Vehicle {
protected:
    std::string licensePlate;
    double fuelConsumption;  // Fuel consumption per km
    double totalFuelConsumed;
    double distanceTravelled;
    std::string schedule;  // Delivery schedule

public:
    Vehicle(std::string plate, double consumption) : licensePlate(plate), fuelConsumption(consumption), totalFuelConsumed(0), distanceTravelled(0), schedule("Available") {}

    // Getter for license plate
    std::string getLicensePlate() const {
        return licensePlate;
    }

    // Schedule management
    virtual void setSchedule(const std::string& newSchedule) {
        schedule = newSchedule;
    }

    std::string getSchedule() const {
        return schedule;
    }

    // Travel method with fuel consumption tracking
    virtual void travel(double distance) {
        if (distance < 0) {
            // throw invalid_argument("Distance cannot be negative.");
            return;
        }
        distanceTravelled += distance;
        totalFuelConsumed += distance * fuelConsumption;
    }

    virtual double calculateFuel(double distance) const {
        return distance * fuelConsumption;
    }

    virtual void printDetails() const {
        std::cout << "License Plate: " << licensePlate << "\n"
             << "Fuel Consumption: " << fuelConsumption << " L/km\n"
             << "Total Distance: " << distanceTravelled << " km\n"
             << "Total Fuel Consumed: " << totalFuelConsumed << " L\n"
             << "Schedule: " << schedule << "\n";
    }

    virtual ~Vehicle() {}
};
#endif