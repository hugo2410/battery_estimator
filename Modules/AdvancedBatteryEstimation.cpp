//
// Created by hugo on 10/11/22.
//

#include "AdvancedBatteryEstimation.h"


AdvancedBatteryEstimation::AdvancedBatteryEstimation(){};

double AdvancedBatteryEstimation::computeRemainingBattery(double initBattery,
                                                                      const std::vector<Coordinates> &waypoints,
                                                                      const  std::unordered_map<Coordinates,
                                                                              WindInfo, boost::hash<Coordinates>> &windData,
                                                                      double energyConsumption){

    Coordinates aircraftPosition = {0,0};
    double distance = 0;
    for (auto waypoint:waypoints){
        // Compute the distance flown between each waypoint
        distance = computeDistance(waypoint, aircraftPosition);
        // Update drone's position
        aircraftPosition = waypoint;
        double speed = airSpeed;
        for (auto windValue: windData){
            double tmpDist = computeDistance(aircraftPosition, windValue.first);
            double windComponent = computeFacingWind(windValue.second);
            speed += computeDecay(windComponent);
        }
        // Update the amount of battery left after having flown to the next waypoint
        if (speed > 0){
            initBattery -= (distance / speed) * (energyConsumption / SECONDSPERHOUR);
        }
    }
    return initBattery;
}

double AdvancedBatteryEstimation::computeFacingWind(WindInfo windValue){

    return windValue.speed * cos(windValue.direction);
}

double AdvancedBatteryEstimation::computeDecay(double speedComponent){
   return 1/(exp(speedComponent));
}


double AdvancedBatteryEstimation::computeDistance(Coordinates point1, Coordinates point2){

    return sqrt(pow((point1.first - point2.first), 2) + pow((point1.second - point2.second), 2));
}