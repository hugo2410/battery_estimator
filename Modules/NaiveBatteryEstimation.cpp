//
// Created by hugo on 09/11/22.
//

#include "NaiveBatteryEstimation.h"
#include "iostream"

NaiveBatteryEstimation::NaiveBatteryEstimation(){};

double NaiveBatteryEstimation::computeRemainingBattery(double initBattery,
                                                                       const std::vector<Coordinates> &waypoints,
                                                                       const  std::unordered_map<Coordinates,
                                                                       WindInfo, boost::hash<Coordinates>> &windData,
                                                                       double energyConsumption){

    double distance = 0;
    Coordinates aircraftPosition = {0,0};
    for (auto waypoint:waypoints) {
        // Compute the distance flown between each waypoint
        distance = sqrt(pow((waypoint.first - aircraftPosition.first), 2) +
                   pow((waypoint.second - aircraftPosition.second), 2));
        aircraftPosition = waypoint;
        // Update the amount of battery left after having flown to the next waypoint
        initBattery -= (distance / airSpeed) * (energyConsumption / SECONDSPERHOUR);

    }
    return initBattery;
}