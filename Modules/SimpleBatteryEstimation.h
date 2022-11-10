//
// Created by hugo on 09/11/22.
//

#ifndef BATTERY_ESTIMATOR_SIMPLEBATTERYESTIMATION_H
#define BATTERY_ESTIMATOR_SIMPLEBATTERYESTIMATION_H

#include "AbstractBatteryEstimation.h"
#include "AbstractError.h"


/*
 * Naive implementation for the battery estimation with constant depletion of the battery, only considering the time
 * it would take to reach the home.
 */

class SimpleBatteryEstimation : public AbstractBatteryEstimation
{
public:
    /*
	 * \brief: Default Constructor
	 */
    SimpleBatteryEstimation();

    /**
    * \brief  Simple function to compute the amount of battery left, it finds the closest point and computes the delta
    * in ground speed due to wind
    * @param initBattery: value of the battery at the beginning of the flight (Wh)
    * @param WayPoints: vector containing the list of coordinates of each waypoint
    * @param WindData: unordered map containing the coordinates of the wind measurements and the speed and direction
    * of the measurements
    * @param energyConsumption: value of the power needed to fly at 30m/s
    * @return Estimation of the remaining battery (Wh)
    */
    double computeRemainingBattery(double initBattery,  const std::vector<Coordinates> &WayPoints,
                                const  std::unordered_map<Coordinates, WindInfo, boost::hash<Coordinates>> &WindData,
                                double energyConsumption);

    /**
    * \brief Computes the longitudinal component of the wind
    * @param windValue: WindInfo object containing the speed (m/s) and the direction (rad)
    * @return Wind speed (m/s) along the aircraft's direction
    */
    double computeHeadWind(WindInfo windValue);

    /**
    * \brief Computes the Euclidean distance between two points
    * @param point1: pair of coordinate
    * @param point2: pair of coordinate
    * @return Distance (m) between the two points
    */
    double computeDistance(Coordinates point1, Coordinates point2);
};


#endif //BATTERY_ESTIMATOR_SIMPLEBATTERYESTIMATION_H
