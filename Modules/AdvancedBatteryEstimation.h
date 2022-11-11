//
// Created by hugo on 10/11/22.
//

#ifndef BATTERY_ESTIMATOR_ADVANCEDBATTERYESTIMATION_H
#define BATTERY_ESTIMATOR_ADVANCEDBATTERYESTIMATION_H

#include "AbstractBatteryEstimation.h"

class AdvancedBatteryEstimation : public AbstractBatteryEstimation
{
public:
    /*
	 * \brief: Default Constructor
	 */
    AdvancedBatteryEstimation();

    /**
    * \brief  Advanced function to compute the amount of battery left, it computes the longitudinal component for each
     * measurement and applies a decay function to each of these values.
    * @param initBattery: value of the battery at the beginning of the flight (Wh)
    * @param WayPoints: vector containing the list of coordinates of each waypoint
    * @param WindData: unordered map containing the coordinates of the wind measurements and the speed and direction
    * of the measurements
    * @param energyConsumption: value of the power needed to fly at 30m/s (Watts)
    * @return Remaining battery energy (Wh)
    */
    double computeRemainingBattery(double initBattery,
                                    const std::vector<Coordinates> &WayPoints,
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

    /**
    * \brief Computes the decay of the value, I used 1/e^(x/10), as I wanted a function which was rapidly decreasing but
     * also a function which would return 1 when x=0
    * @param distance: distance to measurement point
    * @return weighted value
    */
    double computeDecay(double distance);
};

#endif //BATTERY_ESTIMATOR_ADVANCEDBATTERYESTIMATION_H
