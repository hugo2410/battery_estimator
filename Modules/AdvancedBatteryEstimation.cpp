//
// Created by hugo on 10/11/22.
//

#include "AdvancedBatteryEstimation.h"


AdvancedBatteryEstimation::AdvancedBatteryEstimation(){};

std::vector<double>  AdvancedBatteryEstimation::computeRemainingBattery(double initBattery,
                                                                      const std::vector<Coordinates> &waypoints,
                                                                      const  std::unordered_map<Coordinates,
                                                                              WindInfo, boost::hash<Coordinates>> &windData,
                                                                      double energyConsumption){

    std::vector<double> batteryEstimation;
    Coordinates aircraftPosition = {0,0};
    double distance = 0, speed = 0;
    for (auto waypoint:waypoints){
        // Compute the distance flown between each waypoint
        distance = computeDistance(waypoint, aircraftPosition);
        // Update drone's position
        aircraftPosition = waypoint;
        // find closest wind measurement to the waypoint
        double closestDistance = 0;
        WindInfo closestMeasurementInfo = {0, 0};
        for (auto windValue: windData){
            double tmpDist = computeDistance(aircraftPosition, windValue.first);
            if (closestDistance > tmpDist){
                closestMeasurementInfo = windValue.second;
                closestDistance = tmpDist;
            }
        }
        speed = airSpeed + computeFacingWind(closestMeasurementInfo);
        // Update the amount of battery left after having flown to the next waypoint
        if (speed > 0){
            initBattery -= (distance / speed) * (energyConsumption / SECONDSPERHOUR);
        }
        batteryEstimation.push_back(initBattery);
    }
    return batteryEstimation;
}

double  AdvancedBatteryEstimation::computeFacingWind(WindInfo windValue){

    return windValue.speed * cos(windValue.direction);
}

double  AdvancedBatteryEstimation::computeDistance(Coordinates point1, Coordinates point2){

    return sqrt(pow((point1.first - point2.first), 2) + pow((point1.second - point2.second), 2));
}