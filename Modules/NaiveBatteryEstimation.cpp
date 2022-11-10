//
// Created by hugo on 09/11/22.
//

#include "NaiveBatteryEstimation.h"

NaiveBatteryEstimation::NaiveBatteryEstimation(){};

std::vector<double>  NaiveBatteryEstimation::computeRemainingBattery(double initBattery,
                                                                       const std::vector<Coordinates> &waypoints,
                                                                       const  std::unordered_map<Coordinates,
                                                                       WindInfo, boost::hash<Coordinates>> &windData,
                                                                       double energyConsumption){

    std::vector<double> batteryEstimation;
    double x = 0, y = 0;
    double distance = 0;
    for (auto waypoint:waypoints){
        // Compute the distance flown between each waypoint
        distance = sqrt(pow((waypoint.first - x), 2) + pow((waypoint.second - y), 2));
        // Update the amount of battery left after having flown to the next waypoint
        initBattery -= (distance / airSpeed) * (energyConsumption / SECONDSPERHOUR);

        batteryEstimation.push_back(initBattery);
    }
    return batteryEstimation;
}