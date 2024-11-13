#include<bits\stdc++.h>

class Route {
private:
    std::string origin;
    std::string destination;
    std::vector<std::string> stops;  // Multiple stops along the route
    double distance;       // Total distance in kilometers

public:
    Route(std::string orig, std::string dest, double dist) : origin(orig), destination(dest), distance(dist) {
        if (dist <= 0) {
            throw std::invalid_argument("Distance must be greater than 0.");
        }
    }

    void addStop(const std::string& stop) {
        stops.push_back(stop);
    }

    double getDistance() const {
        return distance;
    }

    void printRoute() const {
        std::cout << "Route: " << origin;
        for (const auto& stop : stops) {
            std::cout << " -> " << stop;
        }
        std::cout << " -> " << destination << " (" << distance << " km)\n";
    }
};

// Fleet management class using templates, adding scheduling and fuel optimization