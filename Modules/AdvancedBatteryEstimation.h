//
// Created by hugo on 10/11/22.
//

#ifndef BATTERY_ESTIMATOR_ADVANCEDBATTERYESTIMATION_H
#define BATTERY_ESTIMATOR_ADVANCEDBATTERYESTIMATION_H

#include "AbstractBatteryEstimation.h"

class AdvancedBatteryEstimation : AbstractBatteryEstimation
{
public:
    /*
	 * \brief: Default Constructor
	 */
    AdvancedBatteryEstimation();

    /**
    * \brief  Simple function to compute the amount of battery left, it finds the closest point and computes the delta
    * in ground speed due to wind
    * @param initBattery: value of the battery at the beginning of the flight (Wh)
    * @param WayPoints: vector containing the list of coordinates of each waypoint
    * @param WindData: unordered map containing the coordinates of the wind measurements and the speed and direction
    * of the measurements
    * @param energyConsumption: value of the power needed to fly at 30m/s
    * @return Vector containing the battery estimates at each waypoint.
    */
    std::vector<double> computeRemainingBattery(double initBattery,
                                                const std::vector<Coordinates> &WayPoints,
                                                const  std::unordered_map<Coordinates, WindInfo, boost::hash<Coordinates>> &WindData,
                                                double energyConsumption);
    /**
    * \brief Computes the longitudinal component of the wind
    * @param windValue: WindInfo object containing the speed (m/s) and the direction (rad)
    * @return Wind speed (m/s) along the aircraft's direction
    */
    double computeFacingWind(WindInfo windValue);

    /**
    * \brief Computes the Euclidean distance between two points
    * @param point1: pair of coordinate
    * @param point2: pair of coordinate
    * @return Distance (m) between the two points
    */
    double computeDistance(Coordinates point1, Coordinates point2);
};

#endif //BATTERY_ESTIMATOR_ADVANCEDBATTERYESTIMATION_H
