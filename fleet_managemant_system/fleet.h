#ifndef FLEET_H
#define FLEET_H

#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <string>
#include "Vehicle.h"  // Assuming a Vehicle base class exists with virtual methods

template <typename T>
class Fleet {
private:
    std::vector<T*> vehicles;           // A fleet can have different types of vehicles
    std::map<std::string, bool> availability;  // To track available vehicles

public:
    // Add a vehicle to the fleet
    void addVehicle(T* vehicle) {
        vehicles.push_back(vehicle);
        availability[vehicle->getSchedule()] = true;
    }

    // Travel all vehicles for a given distance
    void travelAll(double distance) {
        for (auto& vehicle : vehicles) {
            try {
                vehicle->travel(distance);
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << "\n";
            }
        }
    }

    // Schedule the vehicle if available
    void scheduleVehicle(const std::string& timeSlot, const std::string& licensePlate) {
        for (auto& vehicle : vehicles) {
            if (vehicle->getSchedule() == "Available" && vehicle->getLicensePlate() == licensePlate) {
                vehicle->setSchedule(timeSlot);
                availability[timeSlot] = false;
                std::cout << "Vehicle " << licensePlate << " scheduled at " << timeSlot << "\n";
                return;
            }
        }
        std::cout << "Vehicle " << licensePlate << " is not available.\n";
    }

    // Optimize vehicle selection based on fuel consumption
    T* optimizeFuel(double distance) {
        T* optimalVehicle = nullptr;
        double minFuel = std::numeric_limits<double>::max();

        for (auto& vehicle : vehicles) {
            double fuelNeeded = vehicle->calculateFuel(distance);
            if (fuelNeeded < minFuel) {
                minFuel = fuelNeeded;
                optimalVehicle = vehicle;
            }
        }

        if (optimalVehicle) {
            std::cout << "Most fuel-efficient vehicle is: " << optimalVehicle->getLicensePlate() << " (Fuel needed: " << minFuel << " L)\n";
        } else {
            std::cout << "No vehicles available for optimization.\n";
        }

        return optimalVehicle;
    }

    // Print fleet details
    void printFleetDetails() const {
        for (const auto& vehicle : vehicles) {
            vehicle->printDetails();
            std::cout << "--------------------------\n";
        }
    }

    // Destructor
    ~Fleet() {
        for (auto& vehicle : vehicles) {
            delete vehicle;
        }
    }
};

#endif  // FLEET_H
