#include <bits/stdc++.h>

class Driver {
private:
    std::string driverID;
    std::string name;
    std::string licenseNumber;
    std::string assignedVehicle;  // Registration number of the assigned vehicle

public:
    // Constructor
    Driver(std::string driverID, std::string name, std::string licenseNumber);

    // Getter and Setter methods
    std::string getDriverID() const;
    std::string getName() const;
    std::string getLicenseNumber() const;
    std::string getAssignedVehicle() const;

    void assignVehicle(std::string vehicleRegNum);

    // Function to log driver activity
    void logActivity(std::string activity);

    ~Driver() {};
};
