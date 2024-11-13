#include "Truck.h"
#include "Van.h"
#include "Route.h"
#include "Fleet.h"

int main() {
    // Create a few vehicles
    Truck* truck1 = new Truck("TRK123", 0.3, 10);  // Truck consumes 0.3L/km, 10 tons capacity
    Van* van1 = new Van("VAN456", 0.2, 15);        // Van consumes 0.2L/km, 15 cubic meters volume

    // Create a fleet and add vehicles
    Fleet<Vehicle> fleet;
    fleet.addVehicle(truck1);
    fleet.addVehicle(van1);

    // Create a route with multiple stops
    Route route("New York", "Los Angeles", 4500);  // 4500 km route
    route.addStop("Chicago");
    route.addStop("Denver");

    // Print route details
    route.printRoute();

    // Fuel optimization: Find the most fuel-efficient vehicle for this route
    std::cout << "Optimizing fuel consumption...\n";
    Vehicle* bestVehicle = fleet.optimizeFuel(route.getDistance());

    // Schedule the best vehicle if available
    if (bestVehicle!=NULL) {
        fleet.scheduleVehicle("08:00 AM - 02:00 PM", bestVehicle->getLicensePlate());
    }

    // Simulate travel for all vehicles in the fleet
    std::cout << "Traveling along the route...\n";
    fleet.travelAll(route.getDistance());

    // Print the fleet details after travel
    std::cout << "\nFleet Details After Travel:\n";
    fleet.printFleetDetails();

    return 0;
}

