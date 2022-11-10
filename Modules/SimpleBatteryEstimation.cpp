//
// Created by hugo on 09/11/22.
//

#include "SimpleBatteryEstimation.h"


SimpleBatteryEstimation::SimpleBatteryEstimation(){};

bool SimpleBatteryEstimation::computeRemainingBattery(double initBattery,
                                                                     const std::vector<Coordinates> &waypoints,
                                                                     const  std::unordered_map<Coordinates,
                                                                             WindInfo, boost::hash<Coordinates>> &windData,
                                                                     double energyConsumption){

    double batteryEstimation;
    Coordinates aircraftPosition = {0,0};
    double distance = 0, speed = 0;
    for (auto waypoint:waypoints){
        // Compute the distance flown between each waypoint
        distance = computeDistance(waypoint, aircraftPosition);
        // Update drone's position
        aircraftPosition = waypoint;
        // find closest wind measurement to the next waypoint
        double closestDistance = std::numeric_limits<double>::infinity();
        Coordinates closestMeasurement = {0, 0};
        WindInfo closestMeasurementInfo = {0, 0};

        for (auto windValue: windData){
            double tmpDist = computeDistance(aircraftPosition, windValue.first);
            // store all of the measurements which are within a certain range
            distanceToMeasurement.push_back(computeDistance(aircraftPosition, windValue.first))
            if (closestDistance > tmpDist){
                closestMeasurementInfo = windValue.second;
                closestMeasurement = windValue.first;
                closestDistance = tmpDist;
            }
        }
        // if they are more than one wind measurement
        if (distanceToMeasurement.size() > 1){
            // use all the measurements which are within a certain range

        }
        speed = airSpeed + computeFacingWind(closestMeasurementInfo);
        // Update the amount of battery left after having flown to the next waypoint
        if (speed > 0){
            initBattery -= (distance / speed) * (energyConsumption / SECONDSPERHOUR);
        } else {
            throw WindError();
        }
    }
    if (initBattery > batteryMargin){
        return true;
    } else {
        return false;
    }
}

double  SimpleBatteryEstimation::computeFacingWind(WindInfo windValue){

    return windValue.speed * cos(windValue.direction);
}

double  SimpleBatteryEstimation::computeDistance(Coordinates point1, Coordinates point2){

    return sqrt(pow((point1.first - point2.first), 2) + pow((point1.second - point2.second), 2));
}