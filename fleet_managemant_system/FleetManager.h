
#include <map>
#include <limits>
#include <iostream>
#include "vehicle.h"
#include "driver.h"
#include <bits/stdc++.h>
#include <vector>

class FleetManager {
private:
    std::vector<Vehicle*> vehicles;  // List of vehicles in the fleet
    std::vector<Driver> drivers;     // List of drivers

public:
    // Constructor
    FleetManager();

    // Functions to manage vehicles
    void addVehicle(Vehicle* vehicle);
    void removeVehicle(std::string regNum);
    Vehicle* getVehicle(std::string regNum) const;
    void displayAllVehicles() const;

    // Functions to manage drivers
    void addDriver(Driver driver);
    void removeDriver(std::string driverID);
    Driver* getDriver(std::string driverID) const;
    void assignDriverToVehicle(std::string regNum,std:: string driverID);

    // Maintenance and fuel logging
    void scheduleVehicleMaintenance(std::string regNum);
    void logFuelUsageForVehicle(std::string regNum, double fuelAmount);

    // Destructor to clean up dynamic memory
    ~FleetManager();
};
