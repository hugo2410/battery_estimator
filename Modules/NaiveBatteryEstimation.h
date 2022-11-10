//
// Created by hugo on 09/11/22.
//

#ifndef BATTERY_ESTIMATOR_NAIVEBATTERYESTIMATION_H
#define BATTERY_ESTIMATOR_NAIVEBATTERYESTIMATION_H

#include "AbstractBatteryEstimation.h"


/*
 * Naive implementation for the battery estimation with constant depletion of the battery, only considering the time
 * it would take to reach the home.
 */
class NaiveBatteryEstimation : public AbstractBatteryEstimation
{
public:
    /*
	 * \brief: Default Constructor
	 */
    NaiveBatteryEstimation();

    /**
    * \brief Naive implementation to compute the amount of battery left
    * @param initBattery: value of the battery at the beginning of the flight (Wh)
    * @param WayPoints: vector containing the list of coordinates of each waypoint
    * @param WindData: unordered map containing the coordinates of the wind measurements and the speed and direction
    * of the measurements
    * @param energyConsumption: value of the power needed to fly at 30m/s
    * @return Estimation of the remaining battery (Wh)
    */
    double computeRemainingBattery(double initBattery,
                                                const std::vector<Coordinates> &WayPoints,
                                                const  std::unordered_map<Coordinates, WindInfo, boost::hash<Coordinates>> &WindData,
                                                double energyConsumption);
};


#endif //BATTERY_ESTIMATOR_NAIVEBATTERYESTIMATION_H
